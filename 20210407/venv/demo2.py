

#else与for循环和while循环进行搭配使用
#如果循环结束，没有执行break，则会执行else语句中的数据，如果是break语句跳出来的，则不会执行else语句的内容
# for i in range(3):
#     pawd=input('请输入密码:')
#     if pawd == '2001':
#         print('密码输入正确')
#         break
#     else:
#         print('密码错误')
# else:
#     print('三次密码均输入错误')


#九九乘法口诀表
# for i in range(1,10):
#     for j in range(1,i+1): #从1开始，实际执行的次数为右边的数减去左边的数的差值，就是执行的次数
#         print(i,'*',j,'=',i*j,end='\t')
#     print()  #换行



#列表，类似于数组
# lst=['hello',30,'love',90]  #可以存储不同的数据类型，存储的是相应的内存空间地址，而非实际的数据
# lst2=list(['hello',30,'li','python'])
# print(lst)
# print(type(lst))
# print(lst.index('hello'))  #在列表中查找数据类型，返回他的下标值，如果列表存在多个相同的数据，则返回最前一个数据的下标
#print(lst.index('hello',1,3))  #在列表查找数据，从下标为1的位置开始查找，但不包括3的位置


#切片操作，实则就是’数组‘的访问操作
lst3 = [10,20,30,40,50,60,70,80]
print(lst3)  #默认是按照前序进行访问的
print(lst3[1:3:1])  #从下标为1的位置进行访问，左闭右开区间，步长为正1，从前往后访问
print(lst[7:1:-1])  #最后一个数值为负数，说明是从后往前开始访问，步长为-1，如果起点和终点未初始化，默认是终点有起点处



