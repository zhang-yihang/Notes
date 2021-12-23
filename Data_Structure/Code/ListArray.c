#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
#define ElemType int

typedef struct Line *List;
struct Line
{
    ElemType Data[MaxSize];
    int Last;
};
//typedef struct Line MLine;
//typedef struct Line *List;
//MLine L;
//List PtrL;

//建立空表
List mkList()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct Line));
    PtrL->Last = -1; //表里的第一个元素的Last是0，那么空列表就是-1
    return PtrL;
}
// 根据索引查找元素
ElemType findKth(int K, List PtrL)
{
    ElemType ret;
    if (K < 0 || K > PtrL->Last)
    {
        printf("K ist illegal\n");
    }
    else
    {
        ret = PtrL->Data[K];
    }
    return ret;
}

// 根据元素查找索引
int find(ElemType X, List PtrL)
{
    int i = 0;
    int ret = -1;
    for (i = 0; i < PtrL->Last + 1; i++)
    {
        if (PtrL->Data[i] == X)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

//插入
void insert(List PtrL, int K, ElemType X)
{
    if (PtrL->Last == MaxSize - 1)
    {
        printf("the List is full\n");
        return;
    }
    if (K < 0 || K > PtrL->Last+1)
    {
        printf("K is illegal\n");
        return;
    }

    for (int i = PtrL->Last; i > K-1; i--)
    {
        PtrL->Data[i + 1] = PtrL->Data[i];
    }
    PtrL->Data[K] = X;
    PtrL->Last++;
    return;
}

//删除
void delet(List PtrL, int K)
{
    if (K < 0 || K > PtrL->Last)
    {
        printf("K is illegal\n");
        return;
    }
    for (int i = K + 1; i < PtrL->Last + 1; i++)
    {
        PtrL->Data[i - 1] = PtrL->Data[i];
    }
    PtrL->Last--;
    return;
}

//算长度
int length(List PtrL)
{
    return PtrL->Last + 1;
}

//末尾添加
void append(List L,ElemType X)
{
    int K=length(L);
    insert(L,K,X);
    return;
}

int main()
{
    List L;
    L=mkList();
    for(int i=0;i<10;i++)
    {
        append(L,i);
    }
    {
        for(int i=0;i<length(L);i++)
        printf("%d ",L->Data[i]);
        printf("Last=%d\n",L->Last);
    }
    insert(L,3,100);
    {
        for(int i=0;i<length(L);i++)
        printf("%d ",L->Data[i]);
        printf("Last=%d\n",L->Last);
    }
    delet(L,0);
    {
        for(int i=0;i<length(L);i++)
        printf("%d ",L->Data[i]);
        printf("Last=%d\n",L->Last);
    }
    ElemType a;
    a=findKth(2,L);
    {
        printf("a=%d\n",a);
    }
    int index;
    index=find(100,L);
    {
        printf("index=%d\n",index);
    }
    return 0;

}
