# coding:utf-8
import itchat
import re

def func_1():
    # 先登录
    itchat.login()

    # 获取好友列表
    friends = itchat.get_friends(update=True)[0:]
    for i in friends:
        # 获取个性签名
        signature = i["Signature"]
    print(signature)
    # 先全部抓取下来 
    # 打印之后你会发现，有大量的span，class，emoji，emoji1f3c3等的字段，因为个性签名中使用了表情符号，这些字段都是要过滤掉的，写个正则和replace方法过滤掉

    for i in friends:
    # 获取个性签名
        signature = i["Signature"].strip().replace("span", "").replace("class", "").replace("emoji", "")
    # 正则匹配过滤掉emoji表情，例如emoji1f3c3等
        rep = re.compile("1f\d.+")
        signature = rep.sub("", signature)
        print(signature)

    # 接来下用jieba分词，然后制作成词云，首先要安装jieba和wordcloud库
    # pip install jieba
    # pip install wordcloud
    # 代码

def func_2():
    itchat.login()
    friends = itchat.get_friends(update=True)[0:]
    tList = []
    for i in friends:
        signature = i["Signature"].replace(" ", "").replace("span", "").replace("class", "").replace("emoji", "")
        rep = re.compile("1f\d.+")
        signature = rep.sub("", signature)
        tList.append(signature)

    # 拼接字符串
    text = "".join(tList)

    # jieba分词
    import jieba
    wordlist_jieba = jieba.cut(text, cut_all=True)
    wl_space_split = " ".join(wordlist_jieba)

    # # wordcloud词云
    # # way 1
    # import matplotlib.pyplot as plt
    # from wordcloud import WordCloud
    # import PIL.Image as Image

    # # 这里要选择字体存放路径，这里是Mac的，win的字体在windows／Fonts中
    # my_wordcloud = WordCloud(background_color="white", max_words=10000, 
    #                          max_font_size=40, random_state=42,
    #                          font_path='./fonts/glyphicons-halflings-regular.ttf').generate(wl_space_split)

    # plt.imshow(my_wordcloud)
    # plt.axis("off")
    # plt.show()

    # way 2
    # wordcloud词云
    import matplotlib.pyplot as plt
    from wordcloud import WordCloud, ImageColorGenerator
    import os
    import numpy as np
    import PIL.Image as Image


    d = os.path.dirname(__file__)
    alice_coloring = np.array(Image.open(os.path.join(d, "./images/3.jpg")))
    my_wordcloud = WordCloud(background_color="white", max_words=10000, mask=alice_coloring,
                             max_font_size=100, random_state=42,
                             font_path='./fonts/simkai.ttf')\
        .generate(wl_space_split)

    image_colors = ImageColorGenerator(alice_coloring)
    plt.imshow(my_wordcloud.recolor(color_func=image_colors))
    plt.imshow(my_wordcloud)
    plt.axis("off")
    plt.show()

    # 保存图片 并发送到手机
    my_wordcloud.to_file(os.path.join(d, "wechat_cloud.png"))
    itchat.send_image("wechat_cloud.png", 'filehelper')


### main program
if __name__ == '__main__':
    print('... start ...')
    # func_1()
    func_2()
    print("... end ...")