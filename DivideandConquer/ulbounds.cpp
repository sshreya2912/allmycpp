#include<iostream>
using namespace std;
#define ll long long
int main()
{

ll a[11]={1,2,3,10,10,10,10,10,10,15,16};
ll n=11;
ll key;
key=16;
//function binary_search() belongs to <algorithm> library and returns boolean
bool present=binary_search(a,a+n,key);
if(present)
cout<<key<<" is present."<<endl;
else
cout<<key<<" is not present.";
//function lower_bound(arr,arr+n,key) belongs to algorithm library
cout<<"lower bound "<<lower_bound(a,a+n,key)-a<<endl;
cout<<"upper bound "<<upper_bound(a,a+n,key)-a<<endl;





}