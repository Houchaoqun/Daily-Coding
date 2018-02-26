# coding=utf8

### Python支持多种图形界面的第三方库
### TK, wxWidgets, QT, GTK
### Python自带的库是支持Tk的Tkinter, 无需安装任何包，就可以直接使用;

### Tkinter
### Python代码会调用内置的Tkinter，Tkinter封装了访问Tk的接口
### Tk是一个图形库，支持多个操作系统，使用Tcl语言开发；
### Tk会调用操作系统提供的本地GUI接口，完成最终的GUI。
### 所以，我们的代码只需要调用Tkinter提供的接口就可以了
### 在GUI中，每个Button、Label、输入框等，都是一个Widget
### 

from Tkinter import *

class Application(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.helloLabel = Label(self, text='Hello, world!')
        self.helloLabel.pack()
        self.quitButton = Button(self, text='Quit', command=self.quit)
        self.quitButton.pack()


import tkMessageBox

class Application2(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.nameInput = Entry(self)
        self.nameInput.pack()
        self.alertButton = Button(self, text='Hello', command=self.hello)
        self.alertButton.pack()

    def hello(self):
        name = self.nameInput.get() or 'world'
        tkMessageBox.showinfo('Message', 'Hello, %s' % name)

app = Application2()
# 设置窗口标题:
app.master.title('Hello World')
# 主消息循环:
app.mainloop()