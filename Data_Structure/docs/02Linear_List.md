- [线性表](#线性表)
  - [线性表的抽象数据类型](#线性表的抽象数据类型)
  - [线性表的储存结构](#线性表的储存结构)
    - [顺序储存](#顺序储存)
    - [链式储存](#链式储存)
      - [静态链表](#静态链表)
      - [循环链表](#循环链表)
      - [双向链表](#双向链表)
- [广义表与多重链表](#广义表与多重链表)
# 线性表
## 线性表的抽象数据类型
名称：线性表  
数据对象集：有n个元素组成的有序列表  
操作集：
* List Makeempty(); 创建空表
* ElementType FindKth(int K,List L); 找元素
* int Find(ElementType X,List L);找索引
* void Insert(ElementType X,int i,List L); 插入
* void Delete(int i,List L); 删除
* int len(List L);算长度
* 末尾添加

## 线性表的储存结构
### 顺序储存
>* 优点  
>1. 方便查找
>* 缺点
>1. 空间有限，不可以扩大
>2. 增加和删除很麻烦

### 链式储存
>* 优点  
>1. 空间无限制
>2. 增加和删除很麻烦
>* 缺点
>1. 查找不方便

#### 静态链表
在顺序储存的基础上，添加一个索引，使链表的增加和删除变得方便。  
```
struct LNode
{
  ElemType Data;
  int Next;
}
```
#### 循环链表
#### 双向链表
# 广义表与多重链表
表的元素可以是另一个表，并不一定使单一元素  