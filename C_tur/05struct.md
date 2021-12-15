- [枚举](#枚举)
- [结构](#结构)
  - [声明结构并创建变量](#声明结构并创建变量)
  - [初始化与访问](#初始化与访问)
  - [结构的运算](#结构的运算)
  - [结构指针](#结构指针)
  - [自定义类型typedef](#自定义类型typedef)
  - [union](#union)
# 枚举
```
#include <stdio.h>
 
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
 
int main()
{
    enum DAY day;
    day = WED;
    printf("%d",day);
    return 0;
}
```
# 结构
## 声明结构并创建变量
```
//one
struct point
{
    int x;
    int y;
};
struct point p1;
//two
struct 
{
    int x;
    int y;
} p1,p2;
//three
struct point
{
    int x;
    int y;
}p1;
```
## 初始化与访问
```
struct point p1={1,2}

struct point p1={.y=2} //(0,2)

p1.x=2;
int i=p1.y;
```
## 结构的运算
```
p1=p2;
p1=(struct point){1,2}; //p1.x=1 p1.y=2
```
## 结构指针
```
struct point p1;
struct point *p;
p=&p1;
(*p).x=1;
p->x=1;
```
## 自定义类型typedef
```
//实际上就是取别名
typedef int zyh;
zyh i <=> int i

typedef struct
{
    int x;
    int y;
} Point;

Point p1;
p1.x=1;
```
## union
```
union Data
{
   int i;
   float f;
   char  str[20];
};
三个变量共用一个内存，所以会覆盖
```