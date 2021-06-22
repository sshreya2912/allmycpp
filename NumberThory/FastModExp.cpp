#include <iostream>
#define ll long long

using namespace std;
ll fastModExp(ll a,ll b,ll m)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(a*res)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
   
}
int main()
{
    int ans;
    ans=fastModExp(5,3,100);
    cout<<ans<<endl;
   
}