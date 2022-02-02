#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct Link_List *LinkList;
struct Link_List
{
    ElemType Data;
    LinkList Next;
};

//建立空表
LinkList LinkList_mkEmpty()
{
    LinkList P = NULL;
    return P;
}
//求表长
int LinkList_len(LinkList PtrL)
{
    LinkList p;
    p = PtrL;
    int j = 0;
    while (p != NULL)
    {
        p = p->Next;
        j++;
    }
    return j;
}

//根据内容找地址，找到返回地址，找不到返回NULL
LinkList LinkList_find(LinkList PtrL, ElemType X)
{
    LinkList p;
    p = PtrL;
    while (p != NULL && p->Data != X)
    {
        p = p->Next;
    }
    return p;
}

//根据索引找内容的地址，找到返回地址，找不到返回NULL
LinkList LinkList_findKth(LinkList PtrL, int K)
{
    LinkList p;
    p = PtrL;
    int i = 1;
    LinkList ret = NULL;
    while (i < K && p->Next != NULL)
    {
        p = p->Next;
        i++;
    }
    if (i == K)
    {
        ret = p;
    }
    return ret;
}

//插入,返回头指针，插入失败返回NULL
LinkList LinkList_insert(LinkList PtrL, int K, ElemType X)
{
    LinkList s, p, ret;
    if (K == 1)
    {
        p = (LinkList)malloc(sizeof(struct Link_List));
        p->Data = X;
        p->Next = PtrL;
        ret = p;
    }
    else
    {
        s = LinkList_findKth(PtrL, K - 1);
        if (s == NULL)
        {
            printf("K is illegal");
            ret = NULL;
        }
        else
        {
            p = (LinkList)malloc(sizeof(struct Link_List));
            p->Data = X;
            p->Next = s->Next;
            s->Next = p;
            ret = PtrL;
        }
    }
    return ret;
}

//删除,
LinkList LinkList_delet(LinkList PtrL, int K)
{
    LinkList s, p, ret;
    if (K == 1)
    {
        s = PtrL;
        if (s == NULL)
        {
            printf("K is illegal,and LinkList is empty");
            ret = NULL;
        }
        else
        {
            PtrL = PtrL->Next;
            free(s);
            ret = PtrL;
        }
    }
    else
    {
        s = LinkList_findKth(PtrL, K - 1);
        if (s == NULL || s->Next == NULL)
        {
            printf("K is illegal");
        }
        else
        {
            p = s->Next;
            s->Next = p->Next;
            free(p);
            ret = PtrL;
        }
    }
    return ret;
}

int main()
{
    //test 创建赋值
    LinkList L = LinkList_mkEmpty();
    for (int i = 1; i < 10; i++)
    {
        L = LinkList_insert(L, i, i);
    }
    {
        LinkList p;
        p = L;
        for (int i = 1; i < LinkList_len(L) + 1; i++)
        {
            printf("%d ", p->Data);
            p = p->Next;
            //printf("%d ",i);
        }
        printf("\n");
    }
    //test 查找
    LinkList zyh;
    int l = 7;
    zyh = LinkList_findKth(L, l);
    printf("ith is %d \n", zyh->Data);
    printf("pointer of ith is %p \n", zyh);
    zyh = LinkList_find(L, l);
    printf("elem i is %d \n", zyh->Data);
    printf("pointer of elem i is %p \n", zyh);

    //test 添加
    L = LinkList_insert(L, 3, 103);
    L = LinkList_insert(L, 1, 101);
    L = LinkList_insert(L, LinkList_len(L) + 1, 100);
    {
        LinkList p;
        p = L;
        for (int i = 1; i < LinkList_len(L) + 1; i++)
        {
            printf("%d ", p->Data);
            p = p->Next;
            //printf("%d ",i);
        }
        printf("\n");
    }

    //test 删除
    L = LinkList_delet(L, 1);
    L = LinkList_delet(L, LinkList_len(L));
    L = LinkList_delet(L, 5);
    {
        LinkList p;
        p = L;
        for (int i = 1; i < LinkList_len(L) + 1; i++)
        {
            printf("%d ", p->Data);
            p = p->Next;
            //printf("%d ",i);
        }
        printf("\n");
    }

    return 0;
}