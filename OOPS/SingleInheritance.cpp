#include<iostream>
using namespace std;
class Base
{
    //if you dont declare it is private
    int data1=10;
    public:
    int data2=20;
    int getData1();
    int getData2();
    void setData();

};
int Base :: getData1()
{
    return data1;
}

class Derived: public Base
{
public:
int Data3;
int getData3();
};
int Derived :: getData3()
{
    return (data2)*getData1();
}

//You know what same old thing, nothing new!

int main()
{
    Derived der;
    cout<<der.getData3()<<endl;

}