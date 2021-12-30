#!/bin/bash
name=(z y h)
echo ${name[0]}
echo ${name[2]}

my_array[0]=1
my_array[1]=z
my_array[2]=y

echo "数组的元素为: ${my_array[*]}"
echo "数组的元素为: ${my_array[@]}"
echo "数组元素个数为: ${#my_array[*]}"
echo "数组元素个数为: ${#my_array[@]}"