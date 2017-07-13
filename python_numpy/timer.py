# -*- encoding: utf-8 -*-
'''
author: hcq
date: 20170713
what is it for: 
1. To calculate time that the program cost.
2. To know how the class works.
   1) timer = ElapsedTimer()    // class ElapsedTimer(object):
   2) def __init__(self):   // __init__ function run once you new an object of class ElapsedTimer()
   3) other funciton(elapsed or elapsed_time) run when you called them.

'''

import numpy as np
import time

class ElapsedTimer(object):
    def __init__(self):
        self.start_time = time.time()
    def elapsed(self,sec):
        if sec < 60:
            return str(sec) + " sec"
        elif sec < (60 * 60):
            return str(sec / 60) + " min"
        else:
            return str(sec / (60 * 60)) + " hr"
    def elapsed_time(self):
        print("Elapsed: %s " % self.elapsed(time.time() - self.start_time) )

if __name__ == '__main__':
    timer = ElapsedTimer()
    step_num = 100
    _sum = 1
    for i in range(step_num):
        _sum *= 2
        print(_sum)

    timer.elapsed_time()
