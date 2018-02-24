import itchat
import numpy as np
import pandas as pd
from collections import defaultdict
import re
import jieba
import os
import matplotlib.pyplot as plt
from wordcloud import WordCloud, ImageColorGenerator
import PIL.Image as Image


def get_count(Sequence):
	counts = defaultdict(int) #初始化一个字典
	for x in Sex:
		counts[x] += 1
	return counts

### main program
if __name__ == '__main__':
	print('... start ...')
	
	itchat.login()
	friends = itchat.get_friends(update=True)
	NickName = friends[0].NickName #获取自己的昵称
	if not os.path.exists(NickName):
		os.mkdir(NickName) #为自己创建一个文件夹

	file = '\%s' %NickName #刚刚创建的那个文件夹的相对路径
	cp = os.getcwd() #当前路径
	path = os.path.join(cp+file) #刚刚创建的那个文件夹的绝对路径
	os.chdir(path) #切换路径

	number_of_friends = len(friends)
	df_friends = pd.DataFrame(friends)	# pandas可以把据处理成 DataFrame，这极大方便了后续分析

	### 分析好友性别
	# 男性为1；女性为2；未知为0
	Sex = df_friends.Sex
	Sex_count = get_count(Sex)

	# pandas为Series提供了一个value_counts()方法，可以更方便统计各项出现的次数
	Sex_count = Sex.value_counts() # defaultdict(int, {0: 31, 1: 292, 2: 245})
	Sex_count.plot(kind = 'bar')
	
	# 好友都来自什么地方
	Province = df_friends.Province
	Province_count = Province.value_counts()
	Province_count = Province_count[Province_count.index!=''] #有一些好友地理信息为空，过滤掉这一部分人。
	province_info = ""
	i = 0
	for item in Province_count.index:
		temp = str(Province_count.index[i]) + "(" + str(Province_count[i]) + ") "
		province_info += temp
		i += 1
	province_info += "\n"
	print(province_info)

	City = df_friends.City #[(df_friends.Province=='北京') | (df_friends.Province=='四川')]
	City_count = City.value_counts()
	City_count = City_count[City_count.index!='']

	city_info = ""
	i = 0
	for item in City_count:
		temp = str(City_count.index[i]) + "(" + str(City_count[i]) + ") "
		city_info += temp
		i += 1
	city_info += "\n"
	print(city_info)
	itchat.send(province_info, 'filehelper') 
	itchat.send(city_info, 'filehelper') 

	file_name_all = NickName+'_basic_inf.txt' 
	write_file = open(file_name_all,'w')
	info = '你共有%d个好友,其中有%d个男生，%d个女生，%d未显示性别。\n' %(number_of_friends, Sex_count[1], Sex_count[2], Sex_count[0])+\
		   '你的朋友主要来自省份：%s(%d)、%s(%d)和%s(%d)。\n' %(Province_count.index[0],Province_count[0],Province_count.index[1],Province_count[1],Province_count.index[2],Province_count[2])+\
		   '主要来自这些城市：%s(%d)、%s(%d)、%s(%d)、%s(%d)、%s(%d)和%s(%d)。\n'%(City_count.index[0],City_count[0],City_count.index[1],City_count[1],City_count.index[2],City_count[2],City_count.index[3],City_count[3],City_count.index[4],City_count[4],City_count.index[5],City_count[5])
	itchat.send(info, 'filehelper') 
	print(info)
	write_file.write(info)
	write_file.write(province_info)
	write_file.write(city_info)
	write_file.close()

	print("... end ...")