#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> xv;
    vector<ll> yv;
    ll x,y;
    for(ll i=0;i<n;i++)
    {
        cin>>x>>y;
        xv.push_back(x);
        yv.push_back(y);

    }
    sort(xv.begin(),xv.end(),greater<ll>());
    sort(yv.begin(),yv.end(),greater<ll>());
    ll diffx=INT_MIN;
    ll diffy=INT_MIN;
    for(ll i=1;i<n;i++)
    {
        diffx=max(xv[i-1]-xv[i],diffx);
         diffy=max(yv[i-1]-yv[i],diffy);
    }
    ll length= diffx-1;
    ll breadth=diffy-1;
    ll ans=(length)*(breadth);
    cout<<ans<<endl;





}