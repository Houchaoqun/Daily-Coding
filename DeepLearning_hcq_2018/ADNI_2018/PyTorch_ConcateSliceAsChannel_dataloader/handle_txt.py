#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import re
import numpy as np

axis_way = "Z"
train_subject_path = "./division_txt_path_" + axis_way + "_entropy51/train_SubjectID_original_" + axis_way + "_entropy51.txt"
val_subject_path = "./division_txt_path_" + axis_way + "_entropy51/validation_SubjectID_original_" + axis_way + "_entropy51.txt"

AD_slice_path = "./AD_original_subjectId_" + axis_way + "_entropy51_path.txt"
NC_slice_path = "./NC_original_subjectId_" + axis_way + "_entropy51_path.txt"

root_path = "/home/reserch/documents/deeplearning/alzheimers_disease_DL/pytorch/dataset_path/original_825_top_entropy51"

def excute(subject_path, folder_name):
    
    subject_list = np.loadtxt(subject_path, dtype=str).tolist()
    AD_slice_list = np.loadtxt(AD_slice_path, dtype=str).tolist()
    NC_slice_list = np.loadtxt(NC_slice_path, dtype=str).tolist()

    AD_slice_list.extend(NC_slice_list)
    slice_list = AD_slice_list

    for subject_strcut in subject_list:
        subject_id = subject_strcut.split("|||")[0]
        
        new_slice_txt_dir = os.path.join(root_path, folder_name + "_slice_txt_" + axis_way)

        if not os.path.exists(new_slice_txt_dir):
            os.makedirs(new_slice_txt_dir)

        new_slice_txt_path = os.path.join(new_slice_txt_dir, subject_id + "_" + folder_name + ".txt")

        with open(new_slice_txt_path, "a") as f:
            for slice_struct in slice_list:
                subject_id_slice = slice_struct.split("|||")[0]
                
                if subject_id == subject_id_slice:
                    f.writelines(slice_struct +"\n")
                    print(subject_id_slice)
                # else:
                #     continue

if __name__=="__main__":

    folder_name = "train"
    excute(train_subject_path, folder_name)
    
    folder_name = "validation"
    excute(val_subject_path, folder_name)