#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import re
import numpy as np


axis_way = "Z"
AD_slice_path = "./original_825_top_entropy51/AD_original_subjectId_" + axis_way + "_entropy51_path.txt"
NC_slice_path = "./original_825_top_entropy51/NC_original_subjectId_" + axis_way + "_entropy51_path.txt"
# pMCI_slice_path = "./original_825_top_entropy51/pMCI_original_subjectId_" + axis_way + "_entropy51_path.txt"
# sMCI_slice_path = "./original_825_top_entropy51/sMCI_original_subjectId_" + axis_way + "_entropy51_path.txt"

dir_path = "/home/reserch/documents/deeplearning/alzheimers_disease_DL/pytorch/dataset_path/original_825_top_entropy51"
root_path = os.path.join(dir_path, "division_txt_path_" + axis_way + "_entropy51")

class subject_struct:

    def __init__(self, subjectID, label):
        self.subjectID = subjectID
        self.label = label


def get_subjectID(slice_path):

    slice_list = np.loadtxt(slice_path, dtype=str).tolist()
    subjectID_list = []

    for i, slice_strcut in enumerate(slice_list):

        subject_id = slice_strcut.split("|||")[0]
        if subject_id not in subjectID_list:
            # print(subject_id)
            subjectID_list.append(subject_id)


    return subjectID_list
        

def divise_subjectID_path(slice_path, label):

    subjectID_list = get_subjectID(slice_path)
    subjectID_lenth = len(subjectID_list)
    # random_list_index = 
    division_num = subjectID_lenth / 5
    count = 0
    division_index = 1

    for item in subjectID_list:

        if count >= division_num:
            division_index += 1
            
            count = 0

        ## save path
        save_path_name = os.path.join(root_path, label + "_division0" + str(division_index) + "_SubjectID_original_" + axis_way + "_entropy51.txt")
        # print(save_path_name)
        with open(save_path_name, "a") as f:
            _info = item + "|||" + label
            f.writelines(_info + "\n")

        count += 1

def copy_txt2txt(source_txt, target_txt):

    with open(target_txt, "a") as target:
        source_txt_list = np.loadtxt(source_txt, dtype=str).tolist()
        for item in source_txt_list:
            target.writelines(item + "\n")

def combine_division_train_val(slice_path, label):

    train_subjectID_txt_path = os.path.join(root_path, "train_SubjectID_original_" + axis_way + "_entropy51.txt")
    validation_subjectID_txt_path = os.path.join(root_path, "validation_SubjectID_original_" + axis_way + "_entropy51.txt")

    as_validaion_index = "division05"

    for division_index in range(5):

        division_path_name = os.path.join(root_path, label + "_division0" + str(division_index+1) + "_SubjectID_original_" + axis_way + "_entropy51.txt")

        if as_validaion_index in division_path_name:
            ### validaion
            copy_txt2txt(division_path_name, validation_subjectID_txt_path)

        else:
            ### train
            copy_txt2txt(division_path_name, train_subjectID_txt_path)


if __name__=="__main__":
    
    ### author: Chaoqun Hou
    ### date: 20180527
    ### 5 division into txt for each label
    divise_subjectID_path(AD_slice_path, "AD")
    divise_subjectID_path(NC_slice_path, "NC")
    # divise_subjectID_path(pMCI_slice_path, "pMCI")
    # divise_subjectID_path(sMCI_slice_path, "sMCI")

    ### combine division
    combine_division_train_val(AD_slice_path, "AD")
    combine_division_train_val(NC_slice_path, "NC")
    # combine_division_train_val(pMCI_slice_path, "pMCI")
    # combine_division_train_val(sMCI_slice_path, "sMCI")
