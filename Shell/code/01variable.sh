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