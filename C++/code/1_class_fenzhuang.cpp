#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    bool setAge(int age) //设置数据有效性（0-1000）
    {
        bool ret;
        if(age>=0&&age<1000)
        {
            m_age = age;
            ret=1;
        }
        else
        {
            ret=0;
            printf("age is illegal");
            m_age=0;
        }
        return ret;

        
    }
    int getAge()
    {
        return m_age;
    }

    string getName()
    {
        return m_name;
    }

    void setPass(int Password)
    {
        password = Password;
    }

private:
    string m_name = "张三"; //只读
    int m_age ;           //读写
    int password;           //只写
};

int main()
{
    Person p1;
    cout<<p1.getName()<<endl;
    p1.setPass(1265);
    p1.setAge(-1);
    p1.setAge(20);
    cout<<p1.getAge()<<endl;


    return 0;
}