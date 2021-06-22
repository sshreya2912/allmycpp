#include<iostream>
#include<cstring>
using namespace std;
//Constructor: it gets initialised along with the object
class Books{
  public:
  Books(string x)//Constructor
  {
     setName(x);
  }
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
    Books book("CreamStone");
    cout<<book.getName()<<endl;
    

    return 0;
}