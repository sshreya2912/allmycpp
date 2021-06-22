#include<iostream>
using namespace std;
//declaring a class and calling a function and variable from a class in int main
class Books{

    public:
    int id=256;
    void printBookID()
    {
        cout<<"Book ID is="<<id<<endl;
    }
};
int main()
{
Books book;
cout<<book.id<<endl;
}