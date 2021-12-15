- [pointer](#pointer)
  - [取地址](#取地址)
  - [指针定义](#指针定义)
  - [指针操作](#指针操作)
  - [指针注意点](#指针注意点)
  - [数组与指针的关系](#数组与指针的关系)
  - [申请动态内存](#申请动态内存)
- [字符](#字符)
  - [定义](#定义)
  - [字符操作](#字符操作)
- [字符串](#字符串)
  - [注意点](#注意点)
  - [字符串的定义](#字符串的定义)
  - [字符串的输入](#字符串的输入)
  - [string.h](#stringh)
# pointer
## 取地址
```
int a=0;
printf("%p",&a); //&后面只能跟变量，不可以是表达式
```
## 指针定义
指针是可以存放地址的变量
```
int i;
int *p = &i;
```
## 指针操作
```
#include<stdio.h>

int f(int *p)
{
    printf("p=%p\n",p);
    printf("*p=%d\n",*p);
    *p=26;
    return 0;
}

int main()
{
    int i = 6;
    printf("&i=%p\n",&i);
    f(&i);
    printf("通过地址函数可以更改外部变量i=%d\n",i);
    return 0;
}
```
## 指针注意点
```
int i;
int *p; //这个*是指变量p是指针
p=&i;
*p=26; //这个*是运算符，取p这个指针所指向的内容
```
## 数组与指针的关系
数组就是指针  
所以数组之间不能直接赋值，因为数组是const类型的指针
```
int a[10];
int *p;
p=a;
p[0]<=>a[0]

int i;
int *p;
p=&i;
p[0]<=>i //把i当作数组
```
## 申请动态内存
```
int *p;
p=(int*)malloc(N*sizeof(int));
free(p); //用完一定下free
```
# 字符
## 定义
字符有两种属性，一个是ASCII，一个是字符
```
#include<stdio.h>
int main()
{
    char a; //输入1
    scanf("%c",&a);
    printf("%c  %d",a,a); //第一个是1，第二个是49，是ASCII码
    return 0;
}
```
## 字符操作
```
char c='A';
c++;
printf("%c\n",c); //B

c=c+'a'-'A';
printf("%c\n",c); //b
```
# 字符串
```
char a[]={'z','y','h','\0'} //最后一个'\0'也可以是整数0,但不建议。
```
## 注意点
* 最后的0不算字符串的长度
* 最后的0标志字符串的结束，不是字符串的一部分
* 对字符串的操作可以用数组，但更多是用指针
* string.h中有很多字符串的操作函数
* 字符串是双引号，字符是单引号
## 字符串的定义
```
char *str="hello";//这种定义方式是不可更改的，字符串会被储存到代码段，是const类型。
char str[]="helli"; //这种定义方式与其他变量相同
char str[10]="hello";
```
## 字符串的输入
```
char str[8];
scanf("%7s",str); //7代表最多读取7个，防止越界
//下面这个是严禁的，因为这并不是字符串，知识定义了一个指针。
char *str;
scanf("%s",str);
```
## string.h
```
size_t strlen(const char *s);计算字符串长度，不包括结尾0
int strcmp(const char *s1,const char *s2);s1>s2:1,s1=s2:0,s1<s2:-1
char *strcpy(char *resrict s1,char *restrict s2) 把s2拷贝到s1,返s1,restrict表示s1与s2不能是重叠的
char *strcat(char *resrict s1,char *restrict s2) 把s2连接到s1后面，返还s1,必须保证s1不越界
//上面两个不安全，会越界，下面两个用n限制加入的字符

char *strncpy(char *resrict s1,char *restrict s2,n) 
char *strncat(char *resrict s1,char *restrict s2,n)

int strncmp(const char *s1,const char *s2,n);比较前n个

strchr(s1, ch);
strrchr(s2,ch);从有往左找
返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
```