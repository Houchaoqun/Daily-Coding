#coding=utf8
# from numpy import *
import itchat
import urllib
import requests
import os

# import PIL.Image as Image
from os import listdir
import math
import time

import io
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
# import urllib.request
# sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='utf8') #改变标准输出的默认编码  
# res=urllib.request.urlopen('http://www.baidu.com')  
# htmlBytes=res.read()  
# print(htmlBytes.decode('utf-8'))  

# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='gb18030')

def get_friend_name():
    itchat.auto_login(hotReload=True)

    #想给谁发信息，先查找到这个朋友,name后填微信备注即可,deepin测试成功
    # users = itchat.search_friends(name='')
    users = itchat.get_friends(update=True)[0:]
    num = 0
    #获取好友全部信息,返回一个列表,列表内是一个字典
    for item in users:
        # print(item['UserName'])
        # print(item['NickName'])

        # msg = ((item['NickName']).decode('gbk', 'ignore')).encode('utf-8') + ", 新年快乐..."
        # print((item['NickName']).decode('utf8').encode('gbk'))
        # print((item['NickName']).decode('gbk', 'ignore'))
        try:
            # print("Alias = {}".format(item['Alias'].decode("utf-8").encode("gbk")))
            # print("DisplayName = {}".format(item['DisplayName'].decode("utf-8").encode("gbk")))
            print("===")
            num = num + 1
            # print("RemarkName = {}".format(item['RemarkName'].decode("utf-8").encode("gbk")))
            # print("NickName = {}".format(item['NickName'].decode("utf-8").encode("gbk")))
            user_name = item['UserName']
            if ((item['RemarkName'])):
                # msg = item['RemarkName'].decode("utf-8").encode("gbk")
                print("UserName = {}".format(item['UserName']))
                # itchat.send(u'%s %s %s'%("祝 ", item['RemarkName'], " 2018除夕&&新年快乐哈~"), toUserName = 'filehelper')
                itchat.send(u'%s %s %s'%("祝 ", item['RemarkName'], " 2018除夕&&新年快乐哈~"), toUserName = user_name)
                
                # print("message = {}".format(u'%s, %s'%(item['RemarkName'], "新年快乐...")))
                # print("msg = {}".format(msg))
            else:
                print("UserName = {}".format(item['UserName']))
                # itchat.send(u'%s %s %s'%("祝 ", item['NickName'], " 2018除夕&&新年快乐哈~"), toUserName = 'filehelper')
                itchat.send(u'%s %s %s'%("祝 ", item['NickName'], " 2018除夕&&新年快乐哈~"), toUserName = user_name)
                # print("UserName = {}".format(item['UserName']))
                # print("message = {}".format(u'%s, %s'%(item['NickName'], "新年快乐...")))
                # msg = item['NickName'].decode("utf-8").encode("gbk")
            time.sleep(2)
        except Exception, e:
            print('Exception = {}'.format(e))

        # print((item['NickName']).decode("utf-8"))
        # print(item['WechatAccount'])
    # print(users[0]['UserName'])
    #获取`UserName`,用于发送消息
    # print("num = {}".format(num))
    # users = itchat.search_friends(name=u'刘雪珠')
    # print("users = {}".format(users[0]['StarFriend']))
    # print("users = {}".format(users[0]['AppAccountFlag']))
    # print("users = {}".format(users[0]['VerifyFlag']))
    # print("users = {}".format(users[0]['HideInputBarFlag']))
    # print("users = {}".format(users[0]['SnsFlag']))
    # print("users = {}".format(users[0]['ContactFlag']))
    # print("users = {}".format(users[0]['Statues']))
    # try:
    #     ### itchat.get_friends 可用字段
    #     ### UserName, 
    #     ### RemarkName 你对当前好友的备注名称 
    #     ### DisplayName, Alias
    #     ### City, Province
    #     ### Signature
    #     ### UniFriend
    #     ### OwnerUin
    #     ### MemberList
    #     ### PYQuanPin
    #     ### RemarkPYInitial
    #     ### Uin
    #     ### AppAccountFlag
    #     ### 
    #     ###
    #     # userName = users[0]['RemarkName']
    #     # # print("userName = {}".format(users[0]))
    #     # msg = users[0]['NickName'] + ", 新年快乐..."
    #     # msg = str(msg.decode("utf-8").encode("gbk"))
    #     # print("msg = {}".format(msg))
    #     users = itchat.search_friends(name=u'刘雪珠')
    #     userName = users[0]['UserName']
    #     msg = users[0]['NickName'] + ", 新年快乐"
    #     msg = str(msg.decode("utf-8").encode("gbk"))
    #     # msg = str(msg)
    #     print("msg = {}".format(msg))
    #     print(type(msg))
    #     itchat.send(u'%s, %s'%(users[0]['NickName'], "新年快乐..."), toUserName = 'filehelper')

    # except Exception, e:
    #     print('Exception = {}'.format(e))

### main program
if __name__ == '__main__':
    print('... start ...')
    get_friend_name()
    print("... end ...")