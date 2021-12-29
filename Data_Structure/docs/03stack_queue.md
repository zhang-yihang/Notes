- [堆栈](#堆栈)
  - [堆栈的抽象数据类型](#堆栈的抽象数据类型)
  - [顺序储存](#顺序储存)
  - [链式储存](#链式储存)
- [队列](#队列)
  - [队列的抽象数据类型](#队列的抽象数据类型)
  - [顺序储存](#顺序储存-1)
    - [循坏队列](#循坏队列)
  - [链式储存](#链式储存-1)
# 堆栈
后入先出,只有一个开口，一段入一段出
## 堆栈的抽象数据类型
名称：堆栈  
数据对象集：有n个元素组成的有限线性表  
```
与列表完全相同  
```
操作集：
* Stack Makeempty(int MaxSize); 创建空堆栈
* int IsFull(Stack S,int MaxSize); 
* void Push(Stack S,ElementType i);
* ElementType Pop(Stack S);
* int IsEmpty(Stack S);
## 顺序储存
## 链式储存
从头部插入  
链表末尾删除不太方便。    

# 队列
先入先出，两个开口，一段入，另一端出
## 队列的抽象数据类型
名称：队列  
数据对象集：有n个元素组成的有限线性表  
```
struct Queue
{
  ElemType Data[MaxSize];
  int rear;
  int front;
}
```
操作集：
* Queue CreatQueue(int MaxSize); 创建空队列
* int IsFull(Queue Q,int MaxSize); 
* void Add(Queue Q,ElementType i);
* ElementType Delete(Queue Q);
* int IsEmpty(Queue Q);
## 顺序储存
### 循坏队列
不要放满  
## 链式储存
表头做front ，表末尾做rear。