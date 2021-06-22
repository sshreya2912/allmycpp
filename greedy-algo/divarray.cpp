#include<iostream>
#include<cmath>
#include<algorithm>
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
    ll orig[n];
    ll a[n/2];
    ll b[n/2];
    for(ll i=0;i<n;i++)
    {
        cin>>orig[i];
    }
    sort(orig,orig+n);
    ll ja=0,jb=0;
    for(ll i=0;i<n;i++)
    {
        if(i%2==0)
        {
          a[ja]=orig[i];
          ja++;
        }
        
        else
        {
            b[jb]=orig[i];
            jb++;
        }
        
    }
    ll mind=0;
    for(ll i=0;i<n/2;i++)
    {
        mind+= abs(a[i]-b[i]);
    }
    ll a1[n/2];
    ll b1[n/2];
    
    for(ll i=0;i<n/2;i++)
    {
        a1[i]=orig[i];
    }
    ll zee=0;
    for(ll i=n/2;i<n;i++)
    {
        b1[zee]=orig[i];
        zee++;
    }
    ll maxd=0;
    for(ll i=0;i<n/2;i++)
    {
        maxd+=abs(a1[i]-b1[i]);
    }
    cout<<mind<<" "<<maxd<<endl;



}
}