#include<iostream>
using namespace std;
struct Person{
    char name[40];
    int age;
    int salary;
};
int main()
{
    Person p1;
    cin>>p1.name>>p1.age>>p1.salary;
    cout<<p1.name<<" "<<p1.age<<" "<<p1.salary<<endl;
    return 0;
}
