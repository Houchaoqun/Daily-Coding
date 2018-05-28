# encoding:utf-8
# from scipy.misc import imread
# img = imread('./alibaba.png')
# print(img.shape)
# print(img[])

import numpy as np
import matplotlib.pylab as plt
from PIL import Image
# 加载图像
img = plt.imread("./unsee_hello.jpg")
print(img.shape)
plt.subplot(121)
plt.imshow(img)

## 
minus_matrix = np.zeros((222, 592, 4))
# img2 = img - minus_matrix
img2 = img
for x in range(222):
	for y in range(592):
		for c in range(4):
			img2[x, y, c] -= minus_matrix[x, y, c]

# print(img[100,100,:])
# print(minus_matrix[100,100,:])

plt.subplot(122)
plt.imshow(img2)


plt.show()
