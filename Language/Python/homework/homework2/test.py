#***********************************************
#> File Name: test.py
#> Author: cogitates
#> Mail: weifengzxq@gmail.com 
#> Created Time: Mon 03 Jun 2019 02:34:35 PM CST
#***********************************************/
#!/usr/bin/python
# -*- coding:utf-8 -*-
import numpy as np
train_path='train.npy'
train_array = np.load(train_path)

test_path = 'test.npy'
test_array = np.load(train_path)

print(train_array)
print("test")
t=train_array[:,0:1]
print(t[::,1])
print("second test")
print(train_array[:,1:2])
print(train_array[1,1])
