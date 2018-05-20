import tensorflow as tf
import numpy as np

## reference: https://blog.csdn.net/hongxue8888/article/details/77159772

batch_size = 16
sample_num = 300
epoch = 2000

## random dataset
X = np.random.rand(sample_num, 1)
Y = 9.9 * X + 10.5

## input variable: 从数据集 X,Y 取值
x = tf.placeholder(tf.float32, shape=(None, 1), name="x-input")
y_label = tf.placeholder(tf.float32, shape=(None, 1), name="y-input")

## weight: random init
# w1 = tf.Variable(tf.random_normal([2, 1], stddev=1, seed=1))
# b1 = tf.Variable(tf.random_normal([2, 1], stddev=1, seed=1))
w1 = tf.Variable(0.)
b1 = tf.Variable(0.)


## 定义模型：一个简单的线性模型，输入乘以权重
# y_predict = tf.add(tf.matmul(x, w1), b1)
y_predict = x*w1 + b1

## 损失函数、优化器
loss = tf.reduce_sum(tf.square(y_predict - y_label))
# loss = tf.losses.mean_squared_error(y, y_)
opt = tf.train.AdamOptimizer(0.001).minimize(loss)

with tf.Session() as sess:
    
    ## Variable init
    init = tf.global_variables_initializer()
    sess.run(init)
    
    ## 
    iter_num = sample_num // batch_size
    for _ in range(epoch):
        for it in range(iter_num):
            bs_start = (it*batch_size)%sample_num
            bs_end = (it*batch_size)%sample_num + batch_size
            sess.run(opt, feed_dict={x: X[bs_start:bs_end], y_label: Y[bs_start:bs_end]})
        
        print("epoch = {}, w1 = {} ||| b1 = {}".format(_, sess.run(w1), sess.run(b1)))
        
        
        
        
        
        
        
### epoch = 72, w1 = 9.89680004119873 ||| b1 = 10.501840591430664
### 