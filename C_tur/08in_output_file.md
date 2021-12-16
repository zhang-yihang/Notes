- [格式化输入输出](#格式化输入输出)
  - [printf](#printf)
    - [格式](#格式)
  - [scanf](#scanf)
    - [格式](#格式-1)
  - [printf与scanf的返回值](#printf与scanf的返回值)
  - [Example](#example)
- [文件的输入输出](#文件的输入输出)
  - [重定向](#重定向)
# 格式化输入输出
## printf
### 格式
```
%[flags][width][.prec][hlL]type
```
|flags|意思|width and .prec|意思 | hlL| 意思|
|:---:|:---:|:---:|:---:|:---:|:---:|
|-|左对齐 |number|输出的字符数 | hh|单个字节 |
|+-|前面放加号或减号 |.number| 小数点后精确位数|h |short |
|(space)|整数留空|*|用参数表示字符数 |l or ll |long or long long |
|0| 用0填充 |.*| 用参数表示精确数| L| long double|

|type | 意思| type|意思 |
|:---:|:---:|:---:|:---:|
| i/d| int|e/E | 指数|
|o | 八进制| c| char|
| x X|十六进制 大写|s | string|
| f/F/G/g|float | p| pointer|
| n|读入输出的个数| a/A|十六进制浮点数|
## scanf
### 格式
```
%[flags][hlL]type
```
大多数与printf相同，列出几个特例  
|flags | 意思| type|意思 |
|:---:|:---:|:---:|:---:|
|*|跳过|[^,] |读取逗号之前的|
## printf与scanf的返回值
scanf返回值是读了几个量  
printf返回值是输出了几个字符，包括换行符  
## Example
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   
    char i[5][10];
    int cnt;
    cnt=scanf("%*[^,],%[^:]:%[^,],%[^:]:%[^;];",i[0],i[1],i[2],i[3]);
    for(int x=0;x<4;x++)
    {      
        printf("cnt=%-*d,i[%d]=%s\n",6,cnt,x,i[x]); 
    }
    printf("double=%.*f",2,6.232132);
    return 0;
}


>>input
xsda,8:00,9:16;

>>output
cnt=4     ,i[0]=8
cnt=4     ,i[1]=00
cnt=4     ,i[2]=9
cnt=4     ,i[3]=16
double=+6.23
```
# 文件的输入输出
## 重定向
```
<指定文件作为输入
>指定文件作为输出

$ ./test > output.txt //把输出结果写入文件
$ ./test < input.txt >output.txt //用文件的内容输入，输出的文件保存到文件

```