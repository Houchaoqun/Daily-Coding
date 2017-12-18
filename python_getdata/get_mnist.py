# Copyright 20170611 . All Rights Reserved.
# author: Chaoqun Hou
# Prerequisites:
# Python 2.7
# gzip, subprocess, numpy
# 
# ==============================================================================
"""Functions for downloading and uzip MNIST data."""
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import gzip
import tarfile
import subprocess
import os
import numpy
from six.moves import urllib

def maybe_download(filename, data_dir, SOURCE_URL):
	"""Download the data from Yann's website, unless it's already here."""
	filepath = os.path.join(data_dir, filename)
	if not os.path.exists(filepath):
		filepath, _ = urllib.request.urlretrieve(SOURCE_URL + filename, filepath)
		statinfo = os.stat(filepath)
		print('Successfully downloaded', filename, statinfo.st_size, 'bytes.')


def check_file(data_dir):
	if os.path.exists(data_dir):
		return True
	else:
		os.mkdir(data_dir)
		return False

def uzip_data(decompression_command, decompression_optional, target_path):
	# uzip mnist data
	cmd = [decompression_command, decompression_optional, target_path]
	print('decompression', target_path)
	subprocess.call(cmd)

def mnist_download(data_dir):
	if check_file(data_dir):
		print(data_dir)
		print('dir mnist already exist.')

		# delete the dir mnist
		# if mnist is existed in your dir, it would delete it and download it again.
		cmd = ['rm', '-rf', data_dir]
		print('delete the dir', data_dir)
		subprocess.call(cmd)
		os.mkdir(data_dir)

	
	SOURCE_URL = 'http://yann.lecun.com/exdb/mnist/'
	data_keys = ['train-images-idx3-ubyte.gz', 'train-labels-idx1-ubyte.gz', 't10k-images-idx3-ubyte.gz', 't10k-labels-idx1-ubyte.gz']
	for filename in data_keys:
		if os.path.isfile(os.path.join(data_dir, filename)):
			print("[warning...]", filename, "already exist.")
		else:
			maybe_download(filename, data_dir, SOURCE_URL)

	# uzip the mnist data.
	uziped_data_keys = ['train-images-idx3-ubyte', 'train-labels-idx1-ubyte', 't10k-images-idx3-ubyte', 't10k-labels-idx1-ubyte']
	for filename in uziped_data_keys:
		if os.path.isfile(os.path.join(data_dir, filename)):
			print("[warning...]", filename, "already exist.")
		else:
			target_path = os.path.join(data_dir, filename)
			uzip_data('gzip', '-d', target_path)
		
def cifar10_download(data_dir):
	if check_file(data_dir):
		print(data_dir)
		print('dir mnist already exist.')

		# delete the dir mnist
		cmd = ['rm', '-rf', data_dir]
		print('delete the dir', data_dir)
		subprocess.call(cmd)
		os.mkdir(data_dir)

	SOURCE_URL = 'https://www.cs.toronto.edu/~kriz/'
	filename = 'cifar-10-python.tar.gz'

	if os.path.isfile(os.path.join(data_dir, filename)):
		print("[warning...]", filename, "already exist.")
	else:
		target_path = os.path.join(data_dir, filename)
		target_url = os.path.join(SOURCE_URL, filename)
		# maybe_download(filename, data_dir, SOURCE_URL)
		cmd = ['curl', target_url, '-o', target_path]
		print('Downloading CIFAR10')
		subprocess.call(cmd)


	decompressioned_name = 'cifar-10-batches-py'
	if os.path.isfile(os.path.join(data_dir, decompressioned_name)):
		print("[warning...]", decompressioned_name, "already exist.")
	else:
		print("data_dir = ",data_dir)
		target_path = os.path.join(data_dir, filename)
		print("target_path = ",target_path)
		tarfile.open(target_path, 'r:gz').extractall(data_dir)

# The Street View House Numbers (SVHN) Dataset
# SVHN download
def svhn_download(data_dir):
	import scipy.io as sio
	# svhn file loader
	def svhn_loader(url, path):
		cmd = ['curl', url, '-o', path]
		subprocess.call(cmd)
		m = sio.loadmat(path)
		return m['X'], m['y']

	if check_file(data_dir):
		print('SVHN was downloaded.')
	else:
		data_url = 'http://ufldl.stanford.edu/housenumbers/train_32x32.mat'
		train_image, train_label = svhn_loader(data_url, os.path.join(data_dir, 'train_32x32.mat'))
		
		data_url = 'http://ufldl.stanford.edu/housenumbers/test_32x32.mat'
		test_image, test_label = svhn_loader(data_url, os.path.join(data_dir, 'test_32x32.mat'))


if __name__ == '__main__':
	print("===== running - input_data() script =====")
	print("Please input [ 1 ] to download the mnist database.")
	print("Please input [ 2 ] to download the cifar10 database.")
	print("Please input [ 3 ] to download the svhn database.")
	print("Please input [ all ] to download the mnist, cifar10 and svhn database.")
	user_input = raw_input()
	print("your input is", user_input)

	# There is no switch function in python.
	#  
	# switch(user_input){
	# 	case '1': print("Download MNIST.");
	# 	case '2': print("Download Cifar10.");
	# 	case '3': print("Download SVHN.");
	# 	case 'all': print("Download MNIST, Cifar10 and SVHN.");
	# }

	if(user_input == '1'):
		mnist_download("./mnist")
	elif(user_input == '2'):
		cifar10_download("./cifar10")
	elif(user_input == '3'):
		svhn_download("./svhn")
	elif(user_input == 'all'):
		mnist_download("./mnist")
		cifar10_download("./cifar10")
		svhn_download("./svhn")
	else:
		print("your input is not correct.")

	print("=============   =============")

