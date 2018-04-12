#!/usr/bin/env python  
# coding = utf-8
import datetime
d1 = datetime.datetime.strptime(raw_input(), '%Y-%m-%d')

now = datetime.datetime(2015,10,18)

print (d1-now).days