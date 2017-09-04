# -*- coding: utf-8 -*-
"""
Created on Fri Aug 25 12:11:41 2017

@author: lineplus
"""

import numpy as np
from skimage import io, color
import matplotlib.pyplot as plt

def color2gray(colorimage):
    grayimage = np.zeros([np.shape(colorimage)[0], np.shape(colorimage)[1]], dtype=np.uint8)
    grayimage = np.uint8((np.uint16(colorimage[:, :, 0]) + np.uint16(colorimage[:, :, 1]) + np.uint16(colorimage[:, :, 2])) / 3)
    
    return(grayimage)


def thresholdimg(image,min_th,max_th):
    
    th_img=((image>min_th)&(image<=max_th))* np.uint8(255)
    return th_img
    

def detectedge(grayimg):
    moveleftimage=grayimg[:, 1:]
    edgeimage = np.uint8(np.abs(np.int16(grayimg[:, 0:-1]) - np.int16(moveleftimage[:, :])))
    
    return(edgeimage)

# read image file
img = io.imread('sunfig.png')

# RGB to Gray translation
grayimage = color2gray(img)


# Binary translation

# global thresholding
thres_image=thresholdimg(grayimage,220,255)


edgeimage = detectedge(thres_image)

# view image file 
imgplot = plt.imshow(edgeimage, cmap='gray')
#plt.show()
