#include <stdio.h>

const int Pi = 3.14;

int main()
{
    //输入整数
    printf("输入两个整数");
    int r;
    int d;
    scanf("%d %d", &r, &d); 
    printf("%d，%d\n", r,d);

    //输入浮点数
    printf("输入两个浮点数");
    double a;
    double b;
    scanf("%lf %lf", &a, &b); 
    printf("%f，%f\n",a,b);


    
    return 0;
}