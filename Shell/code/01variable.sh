#!/bin/bash
#author Zhang-Yihang<zhang_yihang@126.com>
my_name="zhang yihang"
echo "可以这么使用变量 ${my_name}"
echo "也可以这样使用变量 $my_name "
unset my_name
echo "$my_name 变量被删除了"
my_name="zhang yihang"
echo "$my_name 又重新定义了变量"
echo "len of ${my_name} is ${#my_name}"
echo "2:4 is ${my_name:2:4}" #ang
echo "location of i is `expr index "$my_name" i` " # 输出 8


echo "传递参数"
echo "执行的文件名 $0"
echo "第一个参数为 $1"
echo "第二个参数为 $2"
echo "第三个参数为 $3"
echo "参数的个数为 $#"
echo "所有参数为 $*"
echo "脚本运行的当前进程ID号 $$"
echo "后台运行的最后一个进程的ID $!"