

#第二天
print('hello world')


# num = int(input('请输入一个数值:'))  #input函数，输出的是一个str类型，所以需要进行强制类型转换
# if num>=90 and num <=100:
#     print('A级')
# elif num>=80 and num<90:
#     print('B级')
# elif num>=70 and num<80:
#     print('C级')
# elif num>=60 and num<70:
#     print('D级')
# else:
#     print('不及格')  #else if 需要进行缩写

#嵌套if elif的使用
# answer = input('你是会员吗y/n')
# money = float(input('请输入消费金额:'))
# if answer == 'y' : #是会员
#     if money >=300:
#         print('打8折，实际付款金额为:',money*0.8) #实际可能会发生精度的偏差，后面会使用到Decimal
#     elif money >=200 and money <300:
#         print('打9折，实际付款金额为:',money*0.9)
#     else:
#         print('不打折，实际付款金额为:',money)
# else: #不是会员
#     if money>=300:
#         print('打九五折，实际付款金额为:',money*0.95)
#     else:
#         print('不打折,实际付款金额为:',money) #这里的嵌套使用，并没有大括号做支持



#条件表达式，即就是三目操作符
# num_a = int(input('请输入一个数值:'))
# num_b = int(input('请输入第二个数值:'))
# print( '大于'  if num_a >= num_b else '小于')  #中间的if语句为真，执行前面的语句，反之，执行后面的语句


#range()函数
#函数参数为1个时，为终点，默认从0出发，步长为1
r=range(10)
print(r)  #range(0, 10),此处打印并非这组所有的数据
print(list(r)) #此处需要使用到列表list，进行整个组的打印操作，[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

r=range(1,20)  #起点和终点，默认步长是1
print(list(r)) #[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]

r=range(1,10,2) #起点，终点，和步长
print(list(r)) #[1, 3, 5, 7, 9]  ,值得注意的是，这个函数生成树数，是左闭右开区间


#for in 循环
#计算1到100之间的偶数和
sum = 0
for i in range(1,101):  #in后面为可迭代的数据
    if i%2==0:
        sum+=i

print('1到100之间的偶数和为:',sum)
