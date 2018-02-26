# coding=utf8

import unittest

class Dict(dict):

    def __init__(self, **kw):
        super(Dict, self).__init__(**kw)

    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'" % key)

    def __setattr__(self, key, value):
        self[key] = value



class TestDict(unittest.TestCase):

### 这两个方法会分别在每调用一个测试方法的前后分别被执行
### 设想你的测试需要启动一个数据库，这时就可以在setUp()方法中连接数据库，在tearDown()方法中关闭数据库

    def setUp(self):
        print 'setUp...'

    def tearDown(self):
        print 'tearDown...'


### 以test开头的方法就是测试方法，不以test开头的方法不被认为是测试方法，测试的时候不会被执行
### 对每一类测试都需要编写一个test_xxx()方法
### 由于unittest.TestCase提供了很多内置的条件判断，我们只需要调用这些方法就可以断言输出是否是我们所期望的
### assertEquals()   self.assertEquals(abs(-1), 1) # 断言函数返回的结果与1相等
### 

    def test_init(self):
        d = Dict(a=1, b='test')
        self.assertEquals(d.a, 1)
        self.assertEquals(d.b, 'test')
        self.assertTrue(isinstance(d, dict))

    def test_key(self):
        d = Dict()
        d['key'] = 'value'
        self.assertEquals(d.key, 'value')

    def test_attr(self):
        d = Dict()
        d.key = 'value'
        self.assertTrue('key' in d)
        self.assertEquals(d['key'], 'value')

    ### 通过d['empty']访问不存在的key时，断言会抛出KeyError
    def test_keyerror(self):
        d = Dict()
        with self.assertRaises(KeyError):
            value = d['empty']

    ### 通过d.empty访问不存在的key时，我们期待抛出AttributeError
    def test_attrerror(self):
        d = Dict()
        with self.assertRaises(AttributeError):
            value = d.empty

### 运行单元测试
### way 1
if __name__ == '__main__':
    unittest.main()

### way 2
### 在命令行通过参数-m unittest直接运行单元测试
### python -m unittest mydict_test