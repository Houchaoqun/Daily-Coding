# -*- coding: utf-8 -*-
import os

import xlrd
import xlwt
import sys

import operator

import StringIO

# reference:
# http://www.cnblogs.com/lhj588/archive/2012/01/06/2314181.html
# http://www.tuicool.com/articles/BFFbUvu

def file_211_985():
    total_students = 0
    count_211_985 = 0
    university_211_985 = []
    # get the 211 university list
    university_list = xlrd.open_workbook('u_985.xlsx')
    university_table = university_list.sheet_by_name(u'211')  # 通过名称获取
    for i in range(university_table.nrows):
        # print (i), university_table.col(0)[i].value
        university_211_985.append(university_table.col(0)[i].value)


    data = xlrd.open_workbook('test2.xlsx')
    # table = data.sheets()[0]    #通过索引顺序获取
    table = data.sheet_by_name(u'Sheet1')   # 通过名称获取
    # table.row_values(i) # 获取整行的值（数组）
    # table.col_values(i) # 获取整列的值（数组）
    nrows = table.nrows
    ncols = table.ncols

    target_data = xlwt.Workbook(encoding="utf-8")
    target_sheet = target_data.add_sheet(u'sheet1')

    target_sheet.write(0, 0, "学号")
    target_sheet.write(0, 1, "姓名")
    target_sheet.write(0, 2, "年级")
    target_sheet.write(0, 3, "前置学历单位")
    target_sheet.write(0, 4, "是否为985/211高校")
    print "university_211_985 length = ", len(university_211_985)

    for i in range(nrows-1):
        current_year = table.col(2)[i + 1].value
        current_year = current_year.strip()
        if ((current_year == "2014") or (current_year == "2015") or (current_year == "2016")):
            # print (i+1),table.col(2)[i+1].value
            print current_year
            total_students = total_students + 1
            target_sheet.write((total_students), 0, table.col(0)[i+1].value)
            target_sheet.write((total_students), 1, table.col(1)[i+1].value)
            target_sheet.write((total_students), 2, table.col(2)[i+1].value)
            target_sheet.write((total_students), 3, table.col(3)[i+1].value)
            flag = False

            for university in university_211_985:
                # print (i + 1)
                # print "university = ",university
                # print "university_len = ", len(university)
                temp = table.col(3)[i + 1].value
                temp = temp.strip()
                # print "table.value = ",temp
                # print "table.value_len = ", len(temp)
                if operator.eq(university, temp):
                    target_sheet.write((total_students), 4, 1)
                    print "===== equal ====="
                    print (i+1)
                    print "university = ",university
                    print "table.value = ",temp
                    flag = True
                    count_211_985 = count_211_985 + 1
                    break

            if flag == False:
                target_sheet.write((total_students), 4, 0)
    # output = StringIO.StringIO()
    # target_data.save(output)
    # output.seek(0)
    # output.getvalue()
    print "total students = ",total_students
    print "[2014-2016]count_211_985 = ", count_211_985
    target_data.save("target_file.xls")

def get_985_211():
    university_list = xlrd.open_workbook('u_985.xlsx')
    table = university_list.sheet_by_name(u'211')  # 通过名称获取
    nrows = table.nrows
    ncols = table.ncols
    for i in range(nrows):
        print (i), table.col(0)[i].value



if __name__=="__main__":
    # get_985_211()
    file_211_985()