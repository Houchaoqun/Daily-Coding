# -*- coding: utf-8 -*-
"""
Created on Fri Mar 30 21:02:35 2018

@author: hcq_lenovo
"""

from PIL import Image
from PIL import ImageFilter
  
im=Image.open('./sum_201803.png')  
im=im.filter(ImageFilter.GaussianBlur(radius=0.1))
  
im.show()