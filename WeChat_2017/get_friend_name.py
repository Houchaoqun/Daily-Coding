#coding=utf8
# from numpy import *
import itchat
import urllib
import requests
import os
from os import listdir
import math
import time
import io
import sys
reload(sys)
sys.setdefaultencoding('utf-8')

def get_friend_name():
    itchat.auto_login(hotReload=True)
    users = itchat.get_friends(update=True)[0:]
    num = 0
    for item in users:
        try:
            num = num + 1
            user_name = item['UserName']
            if ((item['RemarkName'])):
                print("UserName = {}".format(item['UserName']))
                itchat.send(u'%s %s %s'%("祝 ", item['RemarkName'], " 2018除夕&&新年快乐哈~"), toUserName = user_name)
            else:
                print("UserName = {}".format(item['UserName']))
                itchat.send(u'%s %s %s'%("祝 ", item['NickName'], " 2018除夕&&新年快乐哈~"), toUserName = user_name)
            time.sleep(2)
        except Exception, e:
            print('Exception = {}'.format(e))

### main program
if __name__ == '__main__':
    print('... start ...')
    get_friend_name()
    print("... end ...")