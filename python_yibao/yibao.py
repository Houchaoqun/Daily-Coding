# -*- coding: utf-8 -*-
import os

import xlrd
import xlwt
import sys

import operator
import StringIO

def handle_ji():
    file_name_all = "jisuanji20161112.xls"
    # 汇总已上交，生成新文档

    ji1_class = (xlrd.open_workbook('ji_1.xls')).sheets()[0]
    ji2_class = (xlrd.open_workbook('ji_2.xls')).sheets()[0]
    un_class = (xlrd.open_workbook('un_stop.xlsx')).sheets()[0]
    ji_name_list = []
    stu_num = 0

    offset_single = 2
    for i in range(ji1_class.nrows - offset_single):
        stu_name = ji1_class.col(1)[i + offset_single].value
        stu_name = stu_name.strip()
        stu_name = stu_name.replace(' ', '')
        if (len(stu_name)>0):
            # print stu_name
            ji_name_list.append(stu_name)
            stu_num = stu_num + 1

    for i in range(ji2_class.nrows - offset_single):
        stu_name = ji2_class.col(1)[i + offset_single].value
        stu_name = stu_name.strip()
        stu_name = stu_name.replace(' ', '')
        if (len(stu_name) > 0):
            # print stu_name
            ji_name_list.append(stu_name)
            stu_num = stu_num + 1


    for i in range(un_class.nrows - offset_single):
        stu_name = un_class.col(2)[i + offset_single].value
        stu_name = stu_name.strip()
        stu_name = stu_name.replace(' ', '')
        if (len(stu_name) > 0):
            # print stu_name
            ji_name_list.append(stu_name)
            stu_num = stu_num + 1

    print "stu_num = ",stu_num


    # 跟总表对比
    all_stu_name_list = []
    ji_class = (xlrd.open_workbook(file_name_all)).sheets()[3]
    all_stu_num = 0

    offset_all = 2  # excel中，有效数据从第几行开始
    for i in range(ji_class.nrows - offset_all):
        stu_name = ji_class.col(2)[i + offset_all].value
        stu_name = stu_name.strip()
        stu_name = stu_name.replace(' ', '')
        if (len(stu_name) > 0):
            # print stu_name
            all_stu_name_list.append(stu_name)
            all_stu_num = all_stu_num + 1

    print "all_stu_num = ",all_stu_num

    Unfinished_num = 0

    target_data = xlwt.Workbook(encoding="utf-8")
    target_sheet = target_data.add_sheet(u'sheet1')
    target_sheet.write(0, 0, "序号")
    target_sheet.write(0, 1, "姓名")
    target_sheet.write(0, 2, "学号")
    target_sheet.write(0, 3, "是否完成")
    # target_sheet.write(0, 4, "联系方式")

    # print "== all_stu_name_list =="
    # for i in range(all_stu_num):
    #     print all_stu_name_list[i]
    #
    # print "== ji_name_list =="
    # for i in range(stu_num):
    #     print ji_name_list[i]

    print ("=== " + file_name_all + " ===")
    for i in range(all_stu_num):
        # 班级学生数在外层循环
        curr_stu_name = all_stu_name_list[i]

        flag = False

        # target_sheet.write(i+1, 0, ji_class.col(0)[i+1].value)
        # target_sheet.write(i+1, 1, ji_class.col(2)[i+1].value)
        # target_sheet.write(i+1, 2, ji_class.col(3)[i+1].value)

        for j in range(stu_num):
            if operator.eq(curr_stu_name, ji_name_list[j]):
                # target_sheet.write(i + 1, 3, "是")
                flag = True
                # print "xxxx"
                break

        if(flag == False):
            Unfinished_num = Unfinished_num + 1
            target_sheet.write(Unfinished_num, 0, ji_class.col(0)[i + 1].value)
            target_sheet.write(Unfinished_num, 1, ji_class.col(2)[i + 1].value)
            target_sheet.write(Unfinished_num, 2, ji_class.col(1)[i + 1].value)
            target_sheet.write(Unfinished_num, 3, "否")
            # target_sheet.write(Unfinished_num, 4, ji_class.col(5)[i + 1].value)
            print "Unfinished: ", curr_stu_name
            # print "stu_num = ", str(ji_class.col(0)[i + 1].value)

    print "Unfinished_num = ",Unfinished_num
    target_data.save("target_file.xls")

if __name__=="__main__":
    print "== start =="
    handle_ji()
    print "== end =="
