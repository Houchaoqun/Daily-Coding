# -*- encoding: utf-8 -*-
# author: Chaoqun Hou
# CreateDate: 2017-06-13
# 
# command examples:
# python transfer_format.py --datasets MNIST
# python transfer_format.py --datasets CIFAR10
# python transfer_format.py --datasets SVHN

from __future__ import print_function
import os
import sys
import tarfile
import subprocess
import argparse
import h5py
import numpy as np

parser = argparse.ArgumentParser(description='Download dataset for SSGAN.')
parser.add_argument('--datasets', metavar='N', type=str, nargs='+', choices=['MNIST', 'SVHN', 'CIFAR10'])

def prepare_h5py(train_image, train_label, test_image, test_label, data_dir, shape=None):
    # concatenate - 多个数组拼接
    # astype - returns a copy of the array converted to the specified type - eg. [ a = a.astype('Float64') ]
    # test:
    # >>> import numpy as np
    # >>> a=np.array([1,2,3])
    # >>> b=np.array([11,22,33])
    # >>> np.concatenate((a,b),axis=0)
    # array([ 1,  2,  3, 11, 22, 33])

    image = np.concatenate((train_image, test_image), axis=0).astype(np.uint8)
    label = np.concatenate((train_label, test_label), axis=0).astype(np.uint8)

    print ('Preprocessing data...')

    import progressbar
    from time import sleep
    bar = progressbar.ProgressBar(maxval=100, widgets=[progressbar.Bar('=', '[', ']'), ' ', progressbar.Percentage()])
    bar.start()

    # h5py(Hierarchical Data Format) - 层次化数据格式
    # 
    f = h5py.File(os.path.join(data_dir, 'data.hy'), 'w')
    data_id = open(os.path.join(data_dir,'id.txt'), 'w')

    range_len = image.shape[0]
    # print("image.shape[0] = ", image.shape[0])
    # image.shape[0] = 70000
    # range_len = 10

    for i in range(range_len):
        if i%(image.shape[0]/100)==0:
            bar.update(i/(image.shape[0]/100))

        # core - hcq
        grp = f.create_group(str(i))
        data_id.write(str(i)+'\n')

        if shape:
            grp['image'] = np.reshape(image[i], shape, order='F')
        else:
            grp['image'] = image[i]
        label_vec = np.zeros(10)
        label_vec[label[i]%10] = 1

        # label - [0 ~ 69999]
        grp['label'] = label_vec.astype(np.bool)
        # print(image[i])

    bar.finish()
    f.close()
    data_id.close()
    return

def tansfer_format_mnist(download_path):
    data_dir = os.path.join(download_path)
    
    num_mnist_train = 60000
    num_mnist_test = 10000

    # ref - fromfile: http://old.sebug.net/paper/books/scipydoc/numpy_intro.html
    #

    fd = open(os.path.join(data_dir,'train-images-idx3-ubyte'))
    loaded = np.fromfile(file=fd,dtype=np.uint8)
    # print("train-images-idx3-ubyte shape = ", loaded.shape)
    # loaded.shape = 47040016
    train_image = loaded[16:].reshape((num_mnist_train,28,28,1)).astype(np.float)

    fd = open(os.path.join(data_dir,'train-labels-idx1-ubyte'))
    loaded = np.fromfile(file=fd,dtype=np.uint8)
    train_label = np.asarray(loaded[8:].reshape((num_mnist_train)).astype(np.float))

    fd = open(os.path.join(data_dir,'t10k-images-idx3-ubyte'))
    loaded = np.fromfile(file=fd,dtype=np.uint8)
    test_image = loaded[16:].reshape((num_mnist_test,28,28,1)).astype(np.float)

    fd = open(os.path.join(data_dir,'t10k-labels-idx1-ubyte'))
    loaded = np.fromfile(file=fd,dtype=np.uint8)
    test_label = np.asarray(loaded[8:].reshape((num_mnist_test)).astype(np.float))

    prepare_h5py(train_image, train_label, test_image, test_label, data_dir)


def tansfer_format_svhn(data_dir):
    import scipy.io as sio
    # svhn file loader
    def svhn_loader(path):
        m = sio.loadmat(path)
        return m['X'], m['y']

    train_image, train_label = svhn_loader(os.path.join(data_dir, 'train_32x32.mat'))
    test_image, test_label = svhn_loader(os.path.join(data_dir, 'test_32x32.mat'))

    prepare_h5py(np.transpose(train_image, (3, 0, 1, 2)), train_label, 
                 np.transpose(test_image, (3, 0, 1, 2)), test_label, data_dir)

def tansfer_format_cifar10(download_path):
    data_dir = os.path.join(download_path)

    # cifar file loader
    def unpickle(file):
        import cPickle
        with open(file, 'rb') as fo:
            dict = cPickle.load(fo)
        return dict

    num_cifar_train = 50000
    num_cifar_test = 10000

    target_path = os.path.join(data_dir, 'cifar-10-batches-py')
    train_image = []
    train_label = []
    for i in range(5):
        fd = os.path.join(target_path, 'data_batch_'+str(i+1))
        dict = unpickle(fd)
        train_image.append(dict['data'])
        train_label.append(dict['labels'])

    train_image = np.reshape(np.stack(train_image, axis=0), [num_cifar_train, 32*32*3])
    train_label = np.reshape(np.array(np.stack(train_label, axis=0)), [num_cifar_train])

    fd = os.path.join(target_path, 'test_batch')
    dict = unpickle(fd)
    test_image = np.reshape(dict['data'], [num_cifar_test, 32*32*3])
    test_label = np.reshape(dict['labels'], [num_cifar_test])

    prepare_h5py(train_image, train_label, test_image, test_label, data_dir, [32, 32, 3])

if __name__ == '__main__':
    print("running - input_data() script...")
    args = parser.parse_args()

    if 'MNIST' in args.datasets:
        tansfer_format_mnist('./mnist')
    elif 'SVHN' in args.datasets:
        tansfer_format_svhn('./svhn')
    elif 'CIFAR10' in args.datasets:
        tansfer_format_cifar10('./cifar10')
    else:
    	print("your parameter input is not correct.")
