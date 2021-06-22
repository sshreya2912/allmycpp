#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

class Base
{
public:
int x;
int y;
void setx();
void sety();
Base()
{
    setx();
}

};
void Base::setx()
{
    x=10;
}
class Derived: public Base
{
 public:
 int getx();
};
int Derived::getx()
{
    return x;
}
int main() 
{
Derived d;
cout<<d.getx();
return 0;
   
}