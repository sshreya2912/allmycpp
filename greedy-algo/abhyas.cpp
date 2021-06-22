#include<iostream>
using namespace std;
#define ll long long
int main()
{
ll t;
cin>>t;
while(t--)
{
    ll x,y;
    cin>>x>>y;
    if(y-x==0)
    {
        cout<<"0"<<endl;
        continue;
    }
    else if(y-x<0)
    {
        if(y-x%2==0)
        cout<<"1"<<endl;
        else
        {
            cout<<"2"<<endl;
        }
        continue;
    }
    else
    {
        if((y-x)%2==0)
        {
            cout<<"2"<<endl; 
        }
        else
        {
            cout<<"1"<<endl; 
        }
        continue;
    }
    
}
}