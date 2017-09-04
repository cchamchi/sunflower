# -*- coding: utf-8 -*-
"""
Created on Fri Sep  1 15:02:25 2017

@author: lineplus
"""

import numpy as np

# array 

# 1d array

array_1d=np.array([1,2,3,4,5])
array_1d_uint8=np.array([1,2,3,4,5],dtype=np.uint8)
print array_1d.shape

array_1d_uint8_ov=np.array([1,2,3,256,257],dtype=np.uint8)
array_1d_uint8_un=np.array([-2,-1,0,4,5],dtype=np.uint8)


# 2d array(row,col)

array_2d32=np.array([[1,2],[3,4],[5,6]],dtype=np.uint8)
print array_2d32.shape

array_2d23=np.array([[1,2,3],[4,5,6]],dtype=np.uint8)
print array_2d23.shape

# 3d array (slice,row,col)

# 3 slice of 2d array

array_2d_0=np.array([[1,140],[3,100],[5,200]],dtype=np.uint8)
array_2d_1=np.array([[7,100],[9,150],[11,20]],dtype=np.uint8)
array_2d_3=np.array([[13,30],[15,20],[17,100]],dtype=np.uint8)

array_3d332=np.array([array_2d_0,array_2d_1,array_2d_3],dtype=np.uint8)
print array_3d332.shape



#####################  slicing    ##########################

s_1d_2=array_1d[1]
s_2d_row2=array_2d32[1,:]
s_2d_col2=array_2d32[:,1]
s_3d_slice2=array_3d332[1,:,:]

s_3d_add=np.int16(array_3d332[0,:,:]) + np.int16(array_3d332[1,:,:])+ np.int16(array_3d332[2,:,:])

s_3d_add=np.clip(s_3d_add)




