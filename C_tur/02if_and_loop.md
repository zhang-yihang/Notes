- [if 语句](#if-语句)
  - [语法结构](#语法结构)
  - [条件判断](#条件判断)
  - [逻辑运算](#逻辑运算)
- [loop](#loop)
  - [语法结构](#语法结构-1)
  - [循环控制](#循环控制)
- [Examples](#examples)
  - [求平均值](#求平均值)
  - [求最大公约数](#求最大公约数)

# if 语句  
## 语法结构  
```
if (a>10)
{
    printf("a>10");
}
else if(a>3)
{
    printf("a>3">)
}
else
{
    printf("a<=3")
}

switch(type) //type必须是整型int
{
    //case 是用来定位的，这个代码从定位出开始运行，一直运行到最近的break为止，所以如果丢掉break则会进入其他分支
    case 1:
        printf();
        break;
    case 2:
        printf();
        break;
    default:
        printf():
        break;
}
```
## 条件判断  
|  符号   | 含义  |  
| :----: | :----: |     
| ==  | 等于 |   
| !=  | 不等于 |  
|   &lt; = | 下雨等于 |  
| &gt; = | 大于等于  |  
| &gt; | 大于  |  
|&lt; | 小于 |  

## 逻辑运算  
|符号|含义|
|:---:|:---:|
|！|非|
|&&|与|
| \|\| |或|

# loop  
## 语法结构
```
while( i>10 )
{
    i--;
}

do
{
    循环语句;
}while(判断);

for(i;i<N;i++>)
{
    循环语句;
}
```
## 循环控制
```
break //跳出循环
continue //跳过当前循环

goto out; //跳出多重循环
out:

```
  

# Examples
## 求平均值
```
#include <stdio.h>

int main(int argc, char **argv) 
{
    int sum = 0;
    int count = 0;
    int num = 0;
    
    scanf("%d",&num);
    while(num != -1)
    {
        sum +=num;
        count++;
        scanf("%d",&num);
    }
    printf("mean=%f",1.0*sum/count);

    return 0;
}
```
## 求最大公约数
辗转相除法
|a|b|t|
|:---:|:---:|:---:|
|12|18|12|
|18|12|6|
|12|6|0|
|6|0|-|
```

#include <stdio.h>

int main(int argc, char **argv) 
{
    int a,b;
    int t;
    a=18;
    b=12;
    while(b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    printf("the gcd of a and b is %d\n",a);
    return 0;
}
```