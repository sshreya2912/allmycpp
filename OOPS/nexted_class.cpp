#include<iostream>
#include<string>
using namespace std;
 class Student{
public:
  string name;
  int roll_no;
  class Address{
      public:
     string gali_number;
     string country;
 };
 Address addr;

};
int main()
{
    Student :: Address ad;
    Student st;
    st.name="Shreya";
    st.roll_no=123;
    st.addr.gali_number=234;
    st.addr.country="India";
    cout<<st.addr.country<<endl;

}