#include<iostream>
#include<cstring>
using namespace std;
//destructor-- this is used to destroy the object when it goes out of scope-(counterpart) 
// compiler has constructor and destructer by default
class Book{
public:
  Book()
  {
    cout<<"You are in a constructor"<<endl;
  }
  ~Book()//this is how a Destructor is initialised
  {
       cout<<"You are in a destructor"<<endl;
  }


};
int main()
{

Book book;
cout<<"This is in betweening ----middle---"<<endl;


}