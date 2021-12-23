#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int

typedef struct Array_List *ArrayList;
struct Array_List
{
    ElemType Data[MaxSize];
    int Last;
};


//建立空表
ArrayList ArrayList_mkempty()
{
    ArrayList PtrL;
    PtrL = (ArrayList)malloc(sizeof(struct Array_List));
    PtrL->Last = -1; //表里的第一个元素的Last是0，那么空列表就是-1
    return PtrL;
}
// 根据索引查找元素
ElemType ArrayList_findKth(int K, ArrayList PtrL)
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
int ArrayList_find(ElemType X, ArrayList PtrL)
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
void ArrayList_insert(ArrayList PtrL, int K, ElemType X)
{
    if (PtrL->Last == MaxSize - 1)
    {
        printf("the ArrayList is full\n");
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
void ArrayList_delet(ArrayList PtrL, int K)
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
int ArrayList_len(ArrayList PtrL)
{
    return PtrL->Last + 1;
}

//末尾添加
void ArrayList_append(ArrayList L,ElemType X)
{
    int K=ArrayList_len(L);
    ArrayList_insert(L,K,X);
    return;
}

int main()
{
    ArrayList L;
    L=ArrayList_mkempty();
    for(int i=0;i<10;i++)
    {
        ArrayList_append(L,i);
    }
    {
        for(int i=0;i<ArrayList_len(L);i++)
        printf("%d ",L->Data[i]);
        printf("Last=%d\n",L->Last);
    }
    ArrayList_insert(L,3,100);
    {
        for(int i=0;i<ArrayList_len(L);i++)
        printf("%d ",L->Data[i]);
        printf("Last=%d\n",L->Last);
    }
    ArrayList_delet(L,0);
    {
        for(int i=0;i<ArrayList_len(L);i++)
        printf("%d ",L->Data[i]);
        printf("Last=%d\n",L->Last);
    }
    ElemType a;
    a=ArrayList_findKth(2,L);
    {
        printf("a=%d\n",a);
    }
    int index;
    index=ArrayList_find(100,L);
    {
        printf("index=%d\n",index);
    }
    return 0;

}
