# -*- coding: utf-8 -*-

import time
import datetime
import os
import shutil

import sys
import math

def hcq_bubble_sort(active_train_samples_list):
    print("hcq_bubble_sort...")
    for i in range(len(active_train_samples_list)-1):
        current_status = False

        for j in range(len(active_train_samples_list) - i -1):

            if active_train_samples_list[j].p_pred_max > active_train_samples_list[j+1].p_pred_max:

                temp = active_train_samples_list[j]
                active_train_samples_list[j] = active_train_samples_list[j+1]
                active_train_samples_list[j+1] = temp

                # active_train_samples_list[j], active_train_samples_list[j+1] = active_train_samples_list[j+1], active_train_samples_list[j]
                
                current_status = True

        if not current_status:
            break

    return active_train_samples_list

class active_train_samples:

    def __init__(self, image_path, p_pred_max, result):
        self.image_path = image_path
        self.p_pred_max = p_pred_max  ## model predict the p of real lable
        self.result = result

if __name__ == '__main__':
    # _str = input()
    # print(_str)