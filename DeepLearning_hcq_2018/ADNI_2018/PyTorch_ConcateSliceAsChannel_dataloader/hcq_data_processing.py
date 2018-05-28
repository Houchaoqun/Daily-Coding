# -*- coding: utf-8 -*-
import random
import os
import numpy as np
import matplotlib.image as mpimg
import matplotlib.pyplot as plt  
import cv2


def read_lists(file_path):
    dataset_list = np.loadtxt(file_path, dtype=str).tolist()
    subjectID_path, labels  = zip(*[(l.split("|||")[0], int(l.split("|||")[1])) for l in dataset_list])
    return subjectID_path, labels

class Dataset_ADNI_TopK:

    def __init__(self, subjectID_list, subjectID_labels, folder_name, shuffled, batch_size, slice_num):

        self.subjectID_list = subjectID_list
        self.subjectID_labels = subjectID_labels
        self.shuffled = shuffled
        self.batch_size = batch_size
        self.len_dataset = len(self.subjectID_list)
        self.slice_num = slice_num
        self.folder_name = folder_name
        self.batch_size_used = batch_size
        
        
        if shuffled == True:
#            len_subjectID_list = len(subjectID_list)
#            random.shuffle(len_subjectID_list)
#            print("original list...")
#            print(self.subjectID_list)
            z = list(zip(self.subjectID_list, self.subjectID_labels))
            random.shuffle(z)
            self.subjectID_list, self.subjectID_labels = [list(l) for l in zip(*z)]
#            print("random list...")
#            print(self.subjectID_list)


    def slice_concatenate(self, index, root_path):

        # for subjectID in self.subjectID_list:
        #     print(subjectID)

        model_img_size = 224

        x = np.zeros((self.batch_size, self.slice_num, model_img_size, model_img_size))
        y = np.zeros(self.batch_size)
        
        for bs in range(self.batch_size):
            
            if (index*self.batch_size + bs) >= self.len_dataset:
                # print("break....")
# ### hcq ###
# ### 20180528 ###
# ### dataloader ###

# batch_size = 16
# train_dataset_num = 344      --> iter_num = train_dataset_num / batch_size = 21
# validation_dataset_num = 86  --> iter_num = validation_dataset_num / batch_size = 5

# # As for train_dataset_num: 
# - iter_num = train_dataset_num / batch_size = 21
# - range(iter_num)[0, 20]: for _iter in iter_num: dealed with = 21 iterations --> 21 x 16 = 336
# - remained samples: 344 - 336 = 8  <-- train_dataset_num % batch_size
# - range(iter_num+1)[0, 21]: 
                
                delete_samples_num = self.batch_size - (self.len_dataset % self.batch_size)
                for ii in range(delete_samples_num):
                    index_delete = self.batch_size - ii - 1
                    x = np.delete(x, index_delete, axis=0)
                    y = np.delete(y, index_delete, axis=0)

                self.batch_size_used = bs
                break
            
#            print("index = {}, dataset_len = {} ||| index*self.batch_size + bs = {}".format(index, self.len_dataset, index*self.batch_size + bs))
            subjectID = self.subjectID_list[index*self.batch_size + bs]
            subjectID_label = self.subjectID_labels[index*self.batch_size + bs]
                
            y[bs] = subjectID_label
            # print(subjectID)
            
            new_slice_txt_path = os.path.join(root_path, subjectID + "_" + self.folder_name + ".txt")
            slice_list = np.loadtxt(new_slice_txt_path, dtype=str).tolist()
                
            
            for i, slice_strcut in enumerate(slice_list):
                # print(slice_strcut.split("|||")[1])
                image = mpimg.imread(slice_strcut.split("|||")[1])
                # image = np.reshape(image, (227, 227))  ## Not work
                image = cv2.resize(image, (model_img_size, model_img_size))
                # print(image.shape)
                # print(i%slice_num)
                x[bs, i%self.slice_num, :, :] = image
                
        ## return a batch_size  pair(images, labels)
        # print("x.shape = {}, y.shape = {}".format(x.shape, y.shape))
        return x, y

    def iter_len(self):
        iter_num = self.len_dataset / self.batch_size
#        print("iter_len = {} ||| len_dataset = {}, batch_size = {}".format(num, self.len_dataset, self.batch_size))
        return iter_num


#train_subject_ID = './path_txt/train_sujectID_majority_select_top51_slices_folder_02.txt'
#val_subject_ID = './path_txt/val_sujectID_majority_select_top51_slices_folder_02.txt'
#train_subject_ID_list, train_subject_ID_label_list = read_lists(train_subject_ID)
#val_subject_ID_list, val_subject_ID_lable_list = read_lists(val_subject_ID)
#
## dataset_train = Dataset_ADNI_TopK(train_subject_ID_list, train_subject_ID_label_list, "train")
## dataset_train.slice_concatenate()
#
#batch_size_subject = 1
#dataset_val = Dataset_ADNI_TopK(val_subject_ID_list, val_subject_ID_lable_list, "val", True, batch_size_subject)
#slice_num = 51
#image, label = dataset_val.slice_concatenate(slice_num)
#dataset_val.iter_len()

