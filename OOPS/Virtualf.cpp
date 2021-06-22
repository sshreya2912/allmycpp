#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

#define ll long long
#define MOD 1000000007
class Base{
    public:
    int var;
    virtual void print()
    {
        cout<<"This is Base class"<<endl;
    }

};
class Derived: public Base{
    public:
    int var;
     void print()
    {
        cout<<"This is Derived class"<<endl;
    }

};
int main() 
{
    Derived d;
Base* b= &d;
//above is a Base class pointer pointing to Derived class
//Access print from it, it will bind its own print() with it
// BUT IF YOU PUT THE KEYWORD VITUAL FUNCTION IN FRONT OF PRINT METHOD IN BASE CLASS IT BINDS DERIVED CLASS METHOD TO THE CALL IN THE MAIN
b->var=67;
b->print();

return 0;
   
}