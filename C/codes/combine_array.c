#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    int max=a;
    if (b>a)
    {
        max=b;
    }
    return max;
}
int min(int a,int b)
{
    int min=a;
    if (b<a)
    {
        min=b;
    }
    return min;
}
int combinable(int a[],int b[])
{
    int ret =1;
    if(a[0]==-1||a[1]==-1||b[0]==-1||b[1]==-1)
    {
        ret=0;
    }
    if(b[1]<a[0]||b[0]>a[1])
    {
        ret=0;
    }
    return ret;
}
void combine(int a[],int b[],int s[])
{
    s[0]=min(a[0],b[0]);
    s[1]=max(a[1],b[1]);
}

int main()
{
    // 读入数据，储存到二维数组
    int num;//存放进来数据的组数
    int sum=0;//用来计算最后的和
    scanf("%d",&num);
    int r[num][2];
    int bool=0;//标志已经完全融合
    for(int i = 0;i<num;i++)
    {
        scanf("%d %d",&r[i][0],&r[i][1]);

    }

    //处理数据
    while(!bool)
    {
        bool=1;
         for(int i=0;i<num-1;i++)
        {
           
            for(int x=1;i+x<num;x++)
            {
                printf("初始i %d %d\n",r[i][0],r[i][1]);
                printf("初始i+x %d %d\n",r[i+x][0],r[i+x][1]);
                printf("can? %d\n",combinable(r[i],r[i+x]));
                
                if(combinable(r[i],r[i+x]))
                {
                    bool=0;
                    combine(r[i],r[i+x],r[i]);
                    printf("combine i %d %d\n",r[i][0],r[i][1]);
                    r[i+x][0]=-1;
                    r[i+x][1]=-1;
                    printf("combine i %d %d\n",r[i][0],r[i][1]);
                }
            }

        }
    }

    for(int i=0;i<num;i++)
    {
        sum +=r[i][1]-r[i][0];
    }
    printf("答案%d",sum);
    
    
    return 0;
}
