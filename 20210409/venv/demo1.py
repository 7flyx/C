

#第三天

#前面几天写了列表增删查改操作，今天学习字典的相关知识
#字典，类似于C语言中的结构体，用大括号表示，前面的称为键，后面的称为值

#字典元素的访问操作
# sorce = {'张三':20,'李四':30,'王五':60}
#
# print(sorce) #会输出全部的数据
# print(sorce['张三'])  #20，这里会输出方括号中对应的数值，而非字典中单引号的数据，只是输出了’：‘后面的数值
# #print(sorce['刘祥'])  #在字典中访问没有的数据，以方括号的形式去访问，会报错
#
# #第二种形式访问--get(键)
# print(sorce.get('张三'))
# print(sorce.get('刘祥'))  #去查找字典中没有的数据，这个函数会返回  None
# print(sorce.get('刘祥',99)) #在访问失败后，可以自定义返回的数值

#字典的增加与删除,与数组的操作很相似，都是以方括号的形象进行
# sorce = {'张三':20,'李四':30,'王五':60}
# sorce['张三'] = 90
# print(sorce)
#
# del sorce['张三']  #删除键 -值
# print(sorce)
#
# sorce.clear() #清空字典数据
# print(sorce)

#字典视图访问--就是分别获取字典中的键与值，或是键值
#sorce = {'张三':20,'李四':30,'王五':60}
#print(sorce.keys(),type(sorce.keys())) #dict_keys(['张三', '李四', '王五']) <class 'dict_keys'>
#print(sorce.values(),type(sorce.values())) #dict_values([20, 30, 60]) <class 'dict_values'>

 #字典的循环遍历
# sorce = {'张三': 20, '李四': 30, '王五': 60}
# for i in sorce:
#     print(i,sorce[i])  #i,拿到的是键，后面的sorcery[i]拿到的是值
#
# #字典生成式--实则就是将两个列表的数据进行整合打包成一个字典
# name = ['花生','牛奶','豆浆']
# price = [5,3,1,10,20]
# d = { name:price for name,price in zip(name,price)}  #运用循环，去访问每一个数据  ,如果数据不一样多，去最短的即可
# print(d)


