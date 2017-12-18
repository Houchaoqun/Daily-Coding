# -*- coding: utf-8 -*-
"""
Created on Wed Sep 27 11:56:48 2017

@author: lenovo
"""

import numpy as np
import matplotlib.pyplot as plt

def Plotting():
    # Compute the x and y coordinates for points on a sine curve
    x = np.arange(0, 3 * np.pi, 0.1)
    y = np.sin(x)
    
    # Plot the points using matplotlib
    plt.plot(x, y)
    plt.show()  # You must call plt.show() to make graphics appear.
    
def Plotting_title():
    x = np.arange(0, 3 * np.pi, 0.1)
    y_sin = np.sin(x)
    y_cos = np.cos(x)
    
    # Plot the points using matplotlib
    plt.plot(x, y_sin)
    plt.plot(x, y_cos)
    plt.xlabel('x axis label')
    plt.ylabel('y axis label')
    plt.title('Sine and Cosine')
    plt.legend(['Sine', 'Cosine'])
    plt.show()
    
    
def Subplots():
    # Compute the x and y coordinates for points on sine and cosine curves
    x = np.arange(0, 3 * np.pi, 0.1)
    y_sin = np.sin(x)
    y_cos = np.cos(x)
    
    # Set up a subplot grid that has height 2 and width 1,
    # and set the first such subplot as active.
    plt.subplot(2, 1, 1)
    
    # Make the first plot
    plt.plot(x, y_sin)
    plt.title('Sine')
    
    # Set the second subplot as active, and make the second plot.
    plt.subplot(2, 1, 2)
    plt.plot(x, y_cos)
    plt.title('Cosine')
    
    # Show the figure.
    plt.show()

def images():
    from scipy.misc import imread, imresize
    img = imread('assets/naruto.jpg')
    img_tinted = img * [1, 0.95, 0.9]
    
    # Show the original image
    plt.subplot(1, 2, 1)
    plt.imshow(img)
    
    # Show the tinted image
    plt.subplot(1, 2, 2)
    
    # A slight gotcha with imshow is that it might give strange results
    # if presented with data that is not uint8. To work around this, we
    # explicitly cast the image to uint8 before displaying it.
    plt.imshow(np.uint8(img_tinted))
    plt.show()

# Plotting()
# Plotting_title()
# Subplots()
images()















