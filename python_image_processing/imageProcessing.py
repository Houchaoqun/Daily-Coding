# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 12:39:25 2017

@author: lenovo
"""

from PIL import Image  
path_image = "./images/hc.jpg"

def img_resize():
    #读取图像  
    im = Image.open(path_image)  
    im.show()  
      
    #原图像缩放为128x128  
    im_resized = im.resize((128, 128))  
    im_resized.show()  

def img_rotate():
    #读取图像  
    im = Image.open(path_image)  
    im.show()  
      
    # 指定逆时针旋转的角度  
    im_rotate = im.rotate(45)   
    im_rotate.show() 

def img_transpose():
    #读取图像  
    im = Image.open(path_image)  
    im.show() 
    
    out = im.transpose(Image.FLIP_LEFT_RIGHT)  
    out = im.transpose(Image.FLIP_TOP_BOTTOM)  
    out = im.transpose(Image.ROTATE_90)  
    out = im.transpose(Image.ROTATE_180)  
    out = im.transpose(Image.ROTATE_270) 

def img_xx():
    print("== img_xx ==")
    import cv
    image = cv.LoadImage(path_image, 1)
    size = (image.width,image.height)
    iUD = cv.CreateImage(size,image.depth,image.nChannels)
    iLR = cv.CreateImage(size,image.depth,image.nChannels)
    iAcross = cv.CreateImage(size,image.depth,image.nChannels)
    h = image.height
    w = image.width
    for i in range(h):
       for j in range(w):
           iUD[h-1-i,j] = image[i,j]
           iLR[i,w-1-j] = image[i,j]
           iAcross[h-1-i,w-1-j] = image[i,j]
    cv.ShowImage('image',image)
    cv.ShowImage('iUD',iUD)
    cv.ShowImage('iLR',iLR)
    cv.ShowImage('iAcross',iAcross)
    cv.WaitKey(0)


if __name__ == '__main__':
    img_transpose()
    
    
    
    
    
    
    