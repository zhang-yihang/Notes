- [变量](#变量)
  - [定义变量](#定义变量)
  - [使用变量](#使用变量)
  - [只读变量](#只读变量)
  - [删除变量](#删除变量)
- [字符串](#字符串)
  - [获得字符串长度](#获得字符串长度)
  - [提取子字符串](#提取子字符串)
  - [查看字符在字符串中的位置](#查看字符在字符串中的位置)
- [传递参数](#传递参数)
- [数组](#数组)
- [运算](#运算)
- [打印](#打印)
  - [echo](#echo)
  - [printf](#printf)
- [if for while](#if-for-while)
  - [if](#if)
  - [for](#for)
  - [while](#while)
  - [break continue](#break-continue)
- [函数](#函数)
- [多个shell脚本共同运行](#多个shell脚本共同运行)
# 变量
## 定义变量
```
my_name="zhang yihang"
```
## 使用变量
```
echo ${my_name}
```
## 只读变量
```
readonly my_name
```
## 删除变量
```
unset my_name //不能删除只读变量
```
# 字符串
## 获得字符串长度
```
echo ${#my_name} 
```
## 提取子字符串
```
echo ${my_name:2:4} #ang
```
## 查看字符在字符串中的位置
```
echo `expr index "$my_name" i`  #输出 8
```
# 传递参数
```
echo "传递参数";
echo "执行的文件名 $0"
echo "第一个参数为 $1"
echo "第二个参数为 $2"
echo "第三个参数为 $3"
echo "参数的个数为 $#"
echo "所有参数为 $*"
echo "脚本运行的当前进程ID号 $$"
echo "后台运行的最后一个进程的ID $!"

$ ./1.sh 1 2 3
```
# 数组
```
name=(z y h )
echo ${name[0]}

my_array[0]=1
my_array[1]=2
my_array[2]=3

echo "数组的元素为: ${my_array[*]}"
echo "数组的元素为: ${my_array[@]}"
echo "数组元素个数为: ${#my_array[*]}"
echo "数组元素个数为: ${#my_array[@]}"
```
# 运算
```
val=`expr $a + $b`  加
val=`expr $a - $b` 减
val=`expr $a \* $b` 乘 
val=`expr $b / $a` 除
val=`expr $b % $a` 取余
if [ $a == $b ] 等
then
   echo "a 等于 b"
fi
if [ $a != $b ] 不等于
then
   echo "a 不等于 b"
fi
if [ $a -eq $b ] 相等
if [ $a -ne $b ] 不相等
if [ $a -gt $b ] 大于
if [ $a -lt $b ] 小于
if [ $a -ge $b ] 大于等于
if [ $a -le $b ] 小于等于
if [ $a -lt 100 -a $b -gt 15 ]  -a  &&  这两个都表示and，都可以用
if [ $a -lt 100 -o $b -gt 100 ] -o ||  这两个都表示or ，都可以用
```

> a 为 "abc"，变量 b 为 "efg"  
> = 	检测两个字符串是否相等，相等返回 true。 	[ $a = $b ] 返回 false。  
> != 	检测两个字符串是否不相等，不相等返回 true。 	[ $a != $b ] 返回 true。  
> -z 	检测字符串长度是否为0，为0返回 true。 	[ -z $a ] 返回 false。  
> -n 	检测字符串长度是否不为 0，不为 0 返回 true。 	[ -n "$a" ] 返回 true。  
> $ 	检测字符串是否为空，不为空返回 true。 	[ $a ] 返回 true。  

# 打印
## echo
```
echo -e "OK! \n" # -e 开启转义
echo -e "OK! \c" # -e 开启转义 \c 不换行
echo "It is a test" > myfile  显示结果定向至文
```
## printf
```
printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg  
```
# if for while
## if
```
if condition1
then
    command1
elif condition2 
then 
    command2
else
    commandN
fi
```
## for
```
for var in item1 item2 ... itemN
do
    command1
    command2
    ...
    commandN
done

#!/bin/bash

for str in This is a string
do
    echo $str
done
```
## while
```
while condition
do
    command
done
```
## break continue
同C语言  
# 函数
```
#!/bin/bash
# author:改自菜鸟教程
funWithReturn(){
    echo "这个函数会对输入的两个数字进行相加运算..."
    echo "输入第一个数字: "
    read aNum
    echo "输入第二个数字: "
    read anotherNum
    echo "两个数字分别为 $aNum 和 $anotherNum !"
    return $(($aNum+$anotherNum))
}
funWithReturn
echo "输入的两个数字之和为 $? !" # $?显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。
funWithParam(){
    echo "第一个参数为 $1 !"
    echo "第二个参数为 $2 !"
    echo "参数总数有 $# 个!"
    echo "作为一个字符串输出所有参数 $* !"
}
funWithParam 1 2
```
# 多个shell脚本共同运行
第一个1.sh
```
#!/bin/bash
echo "this is 1.sh"
```
第二个2.sh
```
#!/bin/bash
./1.sh
echo "this is 2.sh"
```