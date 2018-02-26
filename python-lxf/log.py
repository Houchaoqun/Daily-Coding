# coding=utf8

import logging
logging.basicConfig(level=logging.INFO)

def foo(s):
    return 10 / int(s)

def bar(s):
    return foo(s) * 2

def main():
    try:
        bar('0')
    except StandardError, e:
        logging.exception(e)

main()
print 'END'


### print
### assert
### loging 
s = '0'
n = int(s)
logging.info('n = %d' % n)

### pdb 程序以单步方式运行，可以随时查看运行状态
### python -m pdb err.py 以参数-m pdb启动后，pdb定位到下一步要执行的代码
### 输入命令l来查看代码；输入命令n可以单步执行代码；任何时候都可以输入命令（p 变量名）来查看变量；输入命令q结束调试，退出程序

### pdb.set_trace()
### 不需要单步执行，我们只需要import pdb，然后，在可能出错的地方放一个pdb.set_trace()，就可以设置一个断点
### 用命令p查看变量，或者用命令c继续运行
### 这个方式比直接启动pdb单步调试效率要高很多，但也高不到哪去