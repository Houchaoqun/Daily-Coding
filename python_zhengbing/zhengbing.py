# -*- coding: utf-8 -*-
import os

import xlrd
import xlwt
import sys

import operator
import StringIO

def handle_ji():
    file_all_boy = "all_boy_18_24.xlsx"
    all_boy = (xlrd.open_workbook(file_all_boy)).sheets()[0]
    all_boy_name_list = []
    all_boy_num = 0

    offset_single = 1
    for i in range(all_boy.nrows - offset_single):
        stu_name = all_boy.col(0)[i + offset_single].value
        stu_name = stu_name.strip()
        stu_name = stu_name.replace(' ', '')
        if (len(stu_name)>0):
            # print stu_name
            all_boy_name_list.append(stu_name)
            all_boy_num = all_boy_num + 1

    print "all_boy_num = ",all_boy_num



    file_all_CST = "CST_all.xlsx"
    all_CST = (xlrd.open_workbook(file_all_CST)).sheets()[0]
    all_CST_name_list = []
    all_CST_num = 0

    offset_single = 1
    for i in range(all_CST.nrows - offset_single):
        stu_name = all_CST.col(1)[i + offset_single].value
        stu_name = stu_name.strip()
        stu_name = stu_name.replace(' ', '')
        if (len(stu_name)>0):
            # print stu_name
            all_CST_name_list.append(stu_name)
            all_CST_num = all_CST_num + 1

    print "all_CST_num = ",all_CST_num



    Unfinished_num = 0
    target_data = xlwt.Workbook(encoding="utf-8")
    target_sheet = target_data.add_sheet(u'sheet1')
    target_sheet.write(0, 0, "姓名")
    target_sheet.write(0, 1, "学号")
    target_sheet.write(0, 2, "专业年级")
    target_sheet.write(0, 3, "联系方式")

    for i in range(all_boy_num):
        # 班级学生数在外层循环
        curr_stu_name = all_boy_name_list[i]
        flag = False

        # target_sheet.write(i+1, 0, ji_class.col(0)[i+1].value)
        # target_sheet.write(i+1, 1, ji_class.col(2)[i+1].value)
        # target_sheet.write(i+1, 2, ji_class.col(3)[i+1].value)

        for j in range(all_CST_num):
            if operator.eq(curr_stu_name, all_CST_name_list[j]):
                # target_sheet.write(i + 1, 3, "是")
                flag = True
                # print "xxxx"
                break

        if(flag == False):
            Unfinished_num = Unfinished_num + 1
            target_sheet.write(Unfinished_num, 0, all_boy.col(0)[i + 1].value)
            target_sheet.write(Unfinished_num, 1, all_boy.col(1)[i + 1].value)
            target_sheet.write(Unfinished_num, 2, all_boy.col(2)[i + 1].value)
            target_sheet.write(Unfinished_num, 3, all_boy.col(3)[i + 1].value)
            print "Unfinished: ", curr_stu_name

    print "Unfinished_num = ",Unfinished_num
    target_data.save("target_file.xls")

if __name__=="__main__":
    print "== start =="
    handle_ji()
    print "== end =="
