# -*- coding: utf-8 -*-
import numpy as np
import tflearn
import os.path

# Download the Titanic dataset
from tflearn.datasets import titanic
titanic.download_dataset('titanic_dataset.csv')

# Load CSV file, indicate that the first column represents labels
from tflearn.data_utils import load_csv


### 数据作预先处理，数据中name对于预测没有什么用处，取消name和ticket两个字段；其次，神经网络只能处理数字，因此，将sex字段男女转为数字0或1。
# Preprocessing function
def preprocess(data, columns_to_ignore):
	# Sort by descending id and delete columns
	for id in sorted(columns_to_ignore, reverse=True):
		[r.pop(id) for r in data]
	for i in range(len(data)):
		# Converting 'sex' field to float (id is 1 after removing labels column)
		data[i][1] = 1. if data[i][1] == 'female' else 0.
	return np.array(data, dtype=np.float32)




def build_network():
	# Build neural network
	net = tflearn.input_data(shape=[None, 6])
	net = tflearn.fully_connected(net, 32)
	net = tflearn.fully_connected(net, 32)
	net = tflearn.fully_connected(net, 2, activation='softmax')
	net = tflearn.regression(net)

	return net


if __name__=="__main__":
	if os.path.isfile('TTNK_model_save.model.meta'):
		print("TTNK_model_save already exists.")
		
	else:
		print("TTNK_model_save is not exists. traning.")

	### 建立分类器数据集存储在csv文件中，能够使用TFlearn的load_csv()函数加载数据，使用target_column作为存活与否的标签，也就是数据集第一列survived，函数返回一对数组(data, label)
	data, labels = load_csv('titanic_dataset.csv', target_column=0, categorical_labels=True, n_classes=2)
	
	# Ignore 'name' and 'ticket' columns (id 1 & 6 of data array)
	to_ignore=[1, 6]
	# Preprocess data
	data = preprocess(data, to_ignore)


	net = build_network()
	# Define model
	model = tflearn.DNN(net)
	# Start training (apply gradient descent algorithm)
	model.fit(data, labels, n_epoch=10, batch_size=16, show_metric=True)

	# save model
	model.save('TTNK_model_save.model')
	



	# Let's create some data for DiCaprio and Winslet
	dicaprio = [3, 'Jack Dawson', 'male', 19, 0, 0, 'N/A', 5.0000]
	winslet = [1, 'Rose DeWitt Bukater', 'female', 17, 1, 2, 'N/A', 100.0000]
	# Preprocess data
	dicaprio, winslet = preprocess([dicaprio, winslet], to_ignore)
	# Predict surviving chances (class 1 results)
	pred = model.predict([dicaprio, winslet])
	print("DiCaprio Surviving Rate:", pred[0][1])
	print("Winslet Surviving Rate:", pred[1][1])

