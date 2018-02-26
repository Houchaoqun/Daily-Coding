# coding=utf8

import json

def json_dumps():
	### Python对象转换到JSON格式: dumps()方法返回一个str，内容就是标准的JSON
	d = dict(name='Bob', age=20, score=88)
	result = json.dumps(d)
	print("result = {}".format(result))

def json_load():
	### JSON反序列化为Python对象
	### loads: 把JSON的字符串反序列化
	### load: 从file-like Object中读取字符串并反序列化

	### 反序列化得到的所有字符串对象默认都是unicode而不是str
	### JSON标准规定JSON编码是UTF-8，我们总是能正确地在Python的str或unicode与JSON的字符串之间转换
	json_str = '{"age": 20, "score": 88, "name": "Bob"}'
	unicode_result = json.loads(json_str)
	print("unicode_result = {}".format(unicode_result))

	### 
	d = dict(name='Bob', age=20, score=88)
	json_str2 = json.dumps(d)
	unicode_result2 = json.loads(json_str2)
	print("unicode_result2 = {}".format(unicode_result2))


### Python的dict对象可以直接序列化为JSON的{}
### 很多时候，我们更喜欢用class表示对象，比如定义Student类，然后序列化
### dumps()方法还提供了一大堆的可选参数   https://docs.python.org/2/library/json.html#json.dumps
def json_improved():

	class Student(object):
		def __init__(self, name, age, score):
			self.name = name
			self.age = age
			self.score = score

	s = Student('Bob', 20, 88)

	### way 1
	### 无法把Student类实例序列化为JSON，是因为默认情况下，dumps()方法不知道如何将Student实例变为一个JSON的{}对象。
	# print(json.dumps(s))  ### TypeError: <__main__.Student object at 0x10aabef50> is not JSON serializable

	### way 2
	### 可选参数default就是把任意一个对象变成一个可序列为JSON的对象
	def student2dict(std):
		return {
			'name': std.name,
			'age': std.age,
			'score': std.score
		}

	print("way 2: {}".format(json.dumps(s, default=student2dict)))

	### way 3
	### 通常class的实例都有一个__dict__属性，它就是一个dict，用来存储实例变量
	print("way 3: {}".format(json.dumps(s, default=lambda obj: obj.__dict__)))


	### 把JSON反序列化为一个Student对象实例，loads()方法首先转换出一个dict对象，
	### 然后，我们传入的object_hook函数负责把dict转换为Student实例
	def dict2student(d):
		return Student(d['name'], d['age'], d['score'])

	json_str = '{"age": 20, "score": 88, "name": "Bob"}'
	deserialization_result = json.loads(json_str, object_hook = dict2student)
	print("json deserialization: {}".format(deserialization_result))
	print("deserialization_result.age = {}".format(deserialization_result.age))

if __name__ == '__main__':
	json_improved()
