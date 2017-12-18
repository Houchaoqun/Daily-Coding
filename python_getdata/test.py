# -*- encoding: utf-8 -*-
# author: Chaoqun Hou
# CreateDate: 2017-06-13
# 
import numpy as np

def progressbar_test():
	import progressbar
	from time import sleep
	bar = progressbar.ProgressBar(maxval=100, widgets=[progressbar.Bar('=', '[', ']'), ' ', progressbar.Percentage()])
	bar.start()

	num = 10000

	for i in range(num):

		bar.update(i/100)

	bar.finish()

def h5py_test():
	import h5py  #导入工具包
	#HDF5的写入：
	imgData = np.zeros((30,3,128,256))  
	f = h5py.File('./test/HDF5_FILE.h5','w')   #创建一个h5文件，文件指针是f
	f['data'] = imgData                 #将数据写入文件的主键data下面
	f['labels'] = range(100)            #将数据写入文件的主键labels下面
	f.close()                           #关闭文件
	  
	#HDF5的读取：  
	f = h5py.File('./test/HDF5_FILE.h5','r')   #打开h5文件
	f.keys()                            #可以查看所有的主键
	a = f['labels'][:]                    #取出主键为data的所有的键值
	print (a)
	f.close()  

def np_file():
	#
	#

	a = np.arange(0,12)
	# print(a)
	a.shape = 3,4 # dim = 3, 4 element in each dim. 
	print(a)
	# print(a.dtype)

	a.tofile("a.bin")
	b = np.fromfile("a.bin", dtype=np.float) # 按照float类型读入数据
	# print(b)
	# print(a.dtype)

	# b = np.fromfile("a.bin", dtype=np.int32) # 按照int32类型读入数据
	# print(b)
	print("================================")
	# print(a.shape)
	print(a[1:])



if __name__ == '__main__':
	# progressbar_test()
	# h5py_test()
	np_file()	