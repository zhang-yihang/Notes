- [array](#array)
  - [定义](#定义)
    - [数组的特点](#数组的特点)
    - [数组越界](#数组越界)
  - [数组的初始化](#数组的初始化)
  - [数组的大小](#数组的大小)
  - [数组的赋值](#数组的赋值)
- [function](#function)
  - [函数的定义](#函数的定义)
  - [函数注意点](#函数注意点)
# array  
## 定义
```
int num[100]; //定义了一个名为num的数组，可以储存100个int的量  
double ages[20];
int num[3][5]; //多维数组 三行五列
```
### 数组的特点
* 数组一旦被定义，大小就不能改变  
* 数组在内存里是连续储存的  
* 数组里的类型必须相同  
* 当数组作为函数参数时，一般需要另一个参数代表数组的大小，在函数内不能用sizeof()计算数组大小  
### 数组越界
```
int num[2];
//num的有效索引为num[0],num[1]
//num[2]越界
```
编译器是不会查数组是否越界，所以有时候即使越界也不报错，但在不同的电脑上有可能报错，所以如果出现难以解释的情况，比如代码在一个电脑上可以跑，在其他地方不能跑，很有可能是越界导致的，所以检查数组是否越界是程序员的责任。
## 数组的初始化
```
int num[10];
for (int i = 0;i<10;i++)
{
    num[i]=0;
}

int num[3]={1,2,3};
int num[]={4,5,6};
int num[2][3]={{1,2,3},
               {4,5,6}};
int num[3]={1}; //{1,0,0}没被定义的自动补0；
int num[5]={[1]=2,4,[4]=3};//{0,2,4,0,3}
```
## 数组的大小
```
int len;
len=sizeof(a)/sizeof(a[0]);
```
## 数组的赋值
~~int a[]={1,2,3};~~  
~~int b[]=a;~~  
```
//只能遍历
for (i;i<len;i++)
{
    b[i]=a[i];
}
```

# function  
## 函数的定义
```
int add(int a,int b)
{
    return a+b;
}
```
## 函数注意点
* 传参
* 不可以在函数中定义函数