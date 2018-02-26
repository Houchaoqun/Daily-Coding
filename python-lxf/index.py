# coding=utf8

class Student(object):
	pass

s = Student()
s2 = Student()
s.name = 'Michael' # 动态给实例绑定一个属性
print s.name

def set_age(self, age): # 定义一个函数作为实例方法
	self.age = age

from types import MethodType
s.set_age = MethodType(set_age, s, Student)
s.set_age(25)
print s.age


def set_score(self, score):
	self.score = score

Student.set_score = MethodType(set_score, None, Student)
s.set_score(100)
s2.set_score(101)
print s.score
print s2.score

### 如果我们想要限制class的属性怎么办？比如，只允许对Student实例添加name和age属性
### Python允许在定义class的时候，定义一个特殊的__slots__变量，来限制该class能添加的属性
### 由于'score'没有被放到__slots__中，所以不能绑定score属性，试图绑定score将得到AttributeError的错误
class Student2(object):
	__slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称

s = Student2()
s.name = 'Michael' # 绑定属性'name'
s.age = 25 # 绑定属性'age'
try:
	s.score = 99 # 绑定属性'score'
except Exception, e:
	print('Exception = {}'.format(e))
