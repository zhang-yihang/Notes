- [树](#树)
  - [树的术语](#树的术语)
  - [树的抽象数据类型](#树的抽象数据类型)
  - [树的表示方法1：二叉树](#树的表示方法1二叉树)
    - [特殊的二叉树](#特殊的二叉树)
    - [二叉树的性质](#二叉树的性质)
    - [二叉树的储存](#二叉树的储存)
      - [顺序储存](#顺序储存)
      - [链表储存](#链表储存)
    - [二叉树的遍历](#二叉树的遍历)
      - [前序后续中序递归](#前序后续中序递归)
      - [非递归中序遍历](#非递归中序遍历)
      - [队列层序遍历](#队列层序遍历)
# 树
## 树的术语
* 根root ：节点 
* 子树subtree
* 节点的度(degree):每个节点子树的个数
* 树的度：节点最大的度
* 父节点(parent)
* 叶节点(leaf)
* 子节点(child)
* 兄弟节点(sibling)
* 节点的层次(level)
* 树的深度(Depth):最大层次
## 树的抽象数据类型
名称：树  
数据对象集：由节点和子树组成的集合  
操作集：
* 创建空树
* 取消树
* 遍历
* 判断是否为空

## 树的表示方法1：二叉树
<!-- ![二叉树图片](./image/binary_tree.png) -->
<img src="image/binary_tree.png" alt="二叉树图片" title="二叉树" width="50%">

### 特殊的二叉树
* 斜二叉树
 > <img src="image/skewed_Btree.jpg" alt="斜二叉树图片" title="斜二叉树" width="50%">
* 完美二叉树/满二叉树
 > <img src="image/perfect_Btree.jpg" alt="完美二叉树图片" title="完美二叉树" width="50%">
* 完全二叉树
 > <img src="image/complete_Btree.jpg" alt="完全二叉树图片" title="完全二叉树" width="50%"> 
### 二叉树的性质
* 第i层的最大节点数为2$^{i-1}$；
* 深度为k的二叉树的最大节点数2$^k$-1
* 对于非空二叉树，叶节点的个数为n$_0$,度为2的节点个数为n$_2$，n$_0$=n$_2$+1  

### 二叉树的储存
#### 顺序储存
* 对于完全二叉树很完美
> <img src="image/Arraytree.png" alt="二叉树顺序储存图片" title="二叉树顺序储存" width="70%">
* 对于一般二叉树会造成空间浪费
> <img src="image/Arraytree2.png" alt="二叉树顺序储存图片" title="二叉树顺序储存" width="70%">
#### 链表储存
```
typedef struct BintreeNode * BinTree;
struct BintreeNode
{
  ElemType Data;
  BinTree Right;
  BinTree Left;

}
```
### 二叉树的遍历
#### 前序后续中序递归
```
void traversal(BinTree BT)
{
  if(BT)
  {
    printf("%d",BT->Data);//现在是前序，放在第二位中序，放在第三位后序
    traversal(BT->Left);
    traversal(BT->Right);
  }
}
```
#### 非递归中序遍历
递归实质就是堆栈，所以直接用堆栈实现遍历
> <img src="image/traversal.png" alt="非递归遍历图片" title="二叉树顺序储存" width="70%">
#### 队列层序遍历
通过队列完成遍历
> <img src="image/traversal2.png" alt="队列层序遍历图片" title="二叉树顺序储存" width="70%">