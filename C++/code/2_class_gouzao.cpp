#include<iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout<<"无参构造函数"<<endl;
    }
    Person(int age)
    {
        m_age=age;
        cout<<"有参构造函数"<<endl;
    }
    Person(const Person &p)
    {
        m_age=p.m_age;
        cout<<"拷贝构造函数"<<endl;
    }
    ~Person()
    {
        cout<<"析构函数"<<endl;
    }
    int m_age;

};
//无参调用
void test()
{
    Person p;
}
//有参调用
void test1()
{
    //方法1
    Person p1(10);
    Person p2(p1);
    //方法2
    //Person(10)是匿名对象，被创建后立刻解析
    //不可以写Person(p3),会被编译器编译为 Person p3,则重定义
    Person p3=Person(10);
    Person p4=Person(p3);
    //方法3
    Person p5=10;
    Person p6=p5;


}