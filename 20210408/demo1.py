
#第三天


#前面讲了切片操作，现在开始了解列表的删除操作
# lst = [10,20,30,40,50,60]
# print(lst)
# lst.remove(10) #现在删除的是括号里的内容，不是下标对应的数据
# print(lst)
#
# lst.pop(1) #现在删除的下标对应的数据 ,例如，此处删除的是列表中，下标为1的数据
# print(lst)
#
# #进行切片操作--运用切片，进行删除数据---切片操作实则是开辟一块新的内存空间，将需要操作的对象放入这个新的列表中
# new_lst = lst[0:2]  #0-1,左闭右开区间
# print('lst',lst)
# print('new_lst',new_lst)
#
# #如何进行，将源列表的数据进行删除，实则进行数据的覆盖即可，将原先的数据区域写入[]
# lst[0:2]=[]
# print(lst)  #运行后的数据为[50, 60]
#
# #列表的清空
# lst.clear()
# print('clear:',lst)
#
# #列表的删除
# del lst
# print(lst)




#列表的修改，分为单个修改和多个修改
# lst = [10,20,30,40]
# lst[1] = 90
# print(lst) #单个修改
# #多个修改，就是运用切片操作
# lst[0:2] = [50,60,70,80]  #50, 60, 70, 80, 30, 40],值得注意的是，这里切片操作，括号中，并不是给出几个位置，就只能给几个数据，而是
# #随便给，将给的数据一起放入指向的数据区域
# print(lst)

#列表的排序操作
lst = [20,50,10,40,100]
print('排序之前:',lst)
lst.sort(reverse=False)  #升序
print('升序操作',lst)  #值得注意的是，这个sort函数，不会产生新的列表，而是在原先的列表进行排序操作
lst.sort(reverse=True)  #降序，reverse = True
print('降序操作',lst)

#第二个排序函数 sorted
print('----------第二个排序函数  sorted-------------')
lst2 = [20,50,10,40,100]
newlst2= sorted(lst2)  #这个函数排序 ，会开辟一个新的列表 ，与sort不一样
print('原列表',lst2)
print('排序列表',newlst2)
#降序
newlst2 = sorted(lst2,reverse=True) #降序
print('降序操作',newlst2)


#列表生成树--就是如何生成一个列表，列表公式
lst = [i for i in range(1,10)]  #实则就是一层for循环，将值i，放入中括号中的最前面，这里的i值也可以进行一些运算，得到相应的数值
print(lst)

#字典的创建
