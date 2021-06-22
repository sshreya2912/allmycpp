#include<iostream>
#include<climits>
using namespace std;
#define ll long long
int main()
{
ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    ll c[n];
    ll l[n];
    for(ll i=0;i<n;i++)
    {
        cin>>c[i];
    }
     for(ll i=0;i<n;i++)
    {
        cin>>l[i];
    }
    ll curprice=INT_MAX;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        curprice=min(curprice,c[i]);
        ans+=curprice*l[i];

    }
    cout<<ans<<endl;

}
}