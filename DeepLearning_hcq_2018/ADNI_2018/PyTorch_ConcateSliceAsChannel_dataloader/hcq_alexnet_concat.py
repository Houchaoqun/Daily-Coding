# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import os
os.environ['CUDA_VISIBLE_DEVICES']='1'

import time
from model_alexnet_concate import alexnet
import torchvision
from torch.autograd import Variable
import torchvision.transforms as transforms
import torchvision.datasets as datasets
from torchvision import models
import torch
import torch.nn as nn
import torch.optim as optim
from torch.optim import lr_scheduler

import matplotlib as mpl
import numpy as np
import matplotlib.pyplot as plt

from hcq_lib import *
from hcq_data_processing import *

slice_num = 51
batch_size_subject = 16
EPOCH = 295
use_gpu = torch.cuda.is_available()

model_name = "alexnet0528"
dataset_name = 'original_825_top_entropy51'
axis_way = "Z"
dir_path = "/home/reserch/documents/deeplearning/alzheimers_disease_DL/pytorch/dataset_path"
root_path = os.path.join(dir_path, dataset_name)
model_save_path = os.path.join('./pytorch_model_original', dataset_name + axis_way + '_EPOCH' + str(EPOCH) + '_' + model_name + '.7t')
save_info_path = os.path.join("./result_train_original", dataset_name + axis_way + '_Concatenate_EPOCH' + str(EPOCH) + '_' + model_name + ".txt")
hcq_write(save_info_path, False, True, "="*20)
hcq_write(save_info_path, True, True, dataset_name)
hcq_write(save_info_path, True, True, model_name)
hcq_write(save_info_path, True, True, model_save_path)

## 
train_acc_list = []
train_loss_list = []
val_acc_list = []
val_loss_list = []

def train(model, epoch, dataset_train, criterion, optimizer):
    
    train_acc = 0.0
    train_loss = 0.0
    total_samples = 0
    iter_num = 0
    hcq_write(save_info_path, False, True, "Epoch = {}/{}".format(epoch+1, EPOCH))

    model.train()
    
    train_path = os.path.join(root_path, "train_slice_txt_" + axis_way)

    for iter_index in range(dataset_train.iter_len()+1):
        inputs, targets = dataset_train.slice_concatenate(iter_index, train_path)
        ##print("inputs shape = {}, targets shape = {}".format(inputs.shape, targets.shape))
        ## inputs shape = (2, 51, 224, 224), targets shape = (2,)
        
        inputs = torch.FloatTensor(inputs)
        targets = torch.LongTensor(targets)
#        print("inputs shape = {}, targets shape = {}".format(inputs.shape, targets.shape))
        ## torch.Size([1, 51, 224, 224]), targets shape = torch.Size([1])
        # wrap them in Variable
        if use_gpu:
            inputs = Variable(inputs.cuda())
            targets = Variable(targets.cuda())
        else:
            inputs, targets = Variable(inputs), Variable(targets)
        
        # zero the parameter gradients
        optimizer.zero_grad()
       
        ## forward
        outputs = model(inputs)
        _, preds = torch.max(outputs.data, 1)
        loss = criterion(outputs, targets)
       
        ## backward
        loss.backward()
        optimizer.step()
       
        ## statistics
        train_loss += loss.data[0]
        total_samples += dataset_train.batch_size_used
        iter_num += 1
        train_acc += preds.eq(targets.data).cpu().sum()

    train_avg_acc = round(100.*train_acc/total_samples, 4)
    train_avg_loss = round(train_loss/(iter_num-1), 4)
        
#    print("train_avg_acc = {}, train_avg_loss = {}".format(train_avg_acc, train_avg_loss))
    hcq_write(save_info_path, True, True, "train_avg_acc = {}({}/{}), train_avg_loss = {}({}/{})".format(
        train_avg_acc, 100.*train_acc, total_samples, train_avg_loss, train_loss, iter_num-1))

    
best_acc = 0.0
def validation(model, epoch, dataset_val, criterion, optimizer):
    
    global best_acc
    global best_epoch
    model.eval()
    val_loss = 0
    correct =0
    total_samples = 0
    iter_num = 0
    # best_acc = 0.0
    
    ## +1: deal with left samples
    ## dataset_len = 43, batch_size = 16 --> iter_len = 43/16 = 2
    ## range(iter_len) --> [0, 1],  index*self.batch_size + bs --> [0, 31]
    ## iter_len + 1 --> deal with [32, 42] samples witch is small than batch_size
    # for iter_index in range(dataset_val.iter_len()+1):   ## when batch_size > 1
    validation_path = os.path.join(root_path, "validation_slice_txt_" + axis_way)
    for iter_index in range(dataset_val.iter_len()):
        # wrap them in Variable
        inputs, targets = dataset_val.slice_concatenate(iter_index, validation_path)
        ##print("inputs shape = {}, targets shape = {}".format(inputs.shape, targets.shape))
        ## inputs shape = (2, 51, 224, 224), targets shape = (2,)
        
        inputs = torch.FloatTensor(inputs)
        targets = torch.LongTensor(targets)
        if use_gpu:
            inputs = Variable(inputs.cuda())
            targets = Variable(targets.cuda())
        else:
            inputs, targets = Variable(inputs), Variable(targets)
            
        # forward
        outputs = model(inputs)
        _, preds = torch.max(outputs.data, 1)
        loss = criterion(outputs, targets)
        
        val_loss += loss.data[0]
#        total_samples += batch_size_subject
        total_samples += 1
        iter_num += 1
        correct += preds.eq(targets.data).cpu().sum()

    val_avg_acc = round(100.*correct/total_samples, 4)
    val_avg_loss = round(val_loss/iter_num, 4)
    
    if val_avg_acc > best_acc:
        # print('Saving..')
        state = {
            'net':model,
            # 'acc': val_avg_acc,
            # 'epoch': epoch,
            # 'optimizer': optimizer.state_dict(),
        }
        
        torch.save(state, model_save_path)
        best_acc = val_avg_acc
        best_epoch = epoch

    hcq_write(save_info_path, True, True, "val_avg_acc = {}({}/{}), val_avg_loss = {}({}/{}) ||| best_acc = {}".format(
        val_avg_acc, 100.*correct, total_samples, val_avg_loss, val_loss, iter_num, best_acc))

    
if __name__ == '__main__':
    
    ### main
    ### train and validation
    since = time.time()

    # display_net()

    model = alexnet(pretrained=False)
    num_classes = 2

    model.classifier = nn.Sequential(
        nn.Dropout(),
        nn.Linear(256 * 6 * 6, 4096),
        nn.ReLU(inplace=True),
        nn.Dropout(),
        nn.Linear(4096, 2048),
        nn.ReLU(inplace=True),
        nn.Linear(2048, num_classes),
    )

    # path_model = "/home/hcq/alzheimer_disease/alzheimer_disease_DL/pytorch/pytorch_model/majority_select_top51_slices_folder_02_AD_NC_EPOCH501_alexnet.7t"
    # checkpoint = torch.load(path_model)
    # model = checkpoint['net']

    if use_gpu:
        model = model.cuda()

    # img_path = os.path.join(data_dir, "validation/AD/067_S_1253_slice_X79.jpg")
    # extract_feature(model, img_path)
    
    lr_feature = 1e-5
    lr_classifier = 1e-5
    lr_gamma = 0.95
    L2_weight_decay = 5e-3
    optimizer_momentum = 0.9
    _info = "lr_feature={}, lr_classifier={}, lr_gamma={}, L2_weight_decay={}, optimizer_momentum={}".format(
        lr_feature, lr_classifier, lr_gamma, L2_weight_decay, optimizer_momentum)
    hcq_write(save_info_path, False, True, _info)
    
    criterion = nn.CrossEntropyLoss()
    # criterion = nn.NLLLoss()

    params = [{'params': model.features.parameters(), 'lr': lr_feature},
               {'params': model.classifier.parameters(), 'lr': lr_classifier}
              ]

    optimizer = optim.Adam(params, lr=1e-4, betas=(0.9, 0.999), weight_decay = L2_weight_decay)
    # optimizer = optim.SGD(params, lr=0.001, momentum=optimizer_momentum, weight_decay = L2_weight_decay)
    exp_lr_scheduler = lr_scheduler.StepLR(optimizer, step_size=10, gamma=lr_gamma)
    ############################################
    
    train_subject_ID = os.path.join(root_path, "division_txt_path_" + axis_way + "_entropy51/train_SubjectID_original_" + axis_way + "_entropy51.txt")
    val_subject_ID = os.path.join(root_path, "division_txt_path_" + axis_way + "_entropy51/validation_SubjectID_original_" + axis_way + "_entropy51.txt")
    train_subject_ID_list, train_subject_ID_label_list = read_lists(train_subject_ID)
    val_subject_ID_list, val_subject_ID_lable_list = read_lists(val_subject_ID)
    
    for epoch in range(EPOCH):
        hcq_write(save_info_path, False, False, "lr_feature = {}, lr_classifier = {}".format(
                optimizer.param_groups[0]['lr'], optimizer.param_groups[1]['lr']))
        exp_lr_scheduler.step()
         
         
        ### dotaloader        
        # train
        dataset_train = Dataset_ADNI_TopK(train_subject_ID_list, train_subject_ID_label_list, "train", True, batch_size_subject, slice_num)
        train(model, epoch, dataset_train, criterion, optimizer)
        
        # val
        dataset_val = Dataset_ADNI_TopK(val_subject_ID_list, val_subject_ID_lable_list, "validation", False, 1, slice_num)
        validation(model, epoch, dataset_val, criterion, optimizer)

    
    time_elapsed = time.time() - since
    hcq_write(save_info_path, True, True, 'Training complete in {:.0f}m {:.0f}s'.format(time_elapsed // 60, time_elapsed % 60))
