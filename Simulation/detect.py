# -*- coding: utf-8 -*-
"""
Created on Fri Aug 25 12:11:41 2017

@author: lineplus
"""

import cv2
import numpy as np

# read image file

img = cv2.imread('sunfig.png')
output = img.copy()

# RGB to Gray translation

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Binary translation

#thresh = cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY_INV,11,2)
# global thresholding
ret,thresh = cv2.threshold(gray,220,255,cv2.THRESH_BINARY)

# view image file 
#cv2.imshow('image',thresh)
#cv2.waitKey(0)
#cv2.destroyAllWindows()

# find egde


# circle detection 

#cv2.HoughCircles(image, method, dp, minDist[,param1[, param2[, minRadius[, maxRadius]]]])
# detect circles in the image
circles = cv2.HoughCircles(thresh, cv2.cv.CV_HOUGH_GRADIENT, 3.7, 100)
# ensure at least some circles were found
print circles

if circles is not None:

	# convert the (x, y) coordinates and radius of the circles to integers
	circles = np.round(circles[0, :]).astype("int")
 
	# loop over the (x, y) coordinates and radius of the circles
	for (x, y, r) in circles:
		# draw the circle in the output image, then draw a rectangle
		# corresponding to the center of the circle
		cv2.circle(output, (x, y), r, (0, 255, 0), 4)
		cv2.rectangle(output, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)
 
	# show the output image
	cv2.imshow("output", np.hstack([img, output]))
	cv2.waitKey(0)
# calculate servo moter 



