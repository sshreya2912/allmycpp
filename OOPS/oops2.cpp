#include<iostream>
#include<cstring>
using namespace std;
//setter and getter
class Books{
public:
    void setName(string x)
    {
     name=x;
    }
    string getName()
    {
     return name;
    }
private:
    string name;
};
int main()
{
Books book;
book.setName("Shreya_theBoss");
cout<<book.getName()<<endl;
return 0;
}