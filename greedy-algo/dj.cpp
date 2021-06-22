#include<iostream>
#include<map>
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
    map<ll,ll> m;
    map<ll,ll> great;
    ll a[n];
    ll b[n];
    for(ll i=0;i<n;i++)
    {
        
       cin>>a[i];
       b[i]=a[i];
    }
    
    ll x;
    ll cost=0;
    
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        m[a[i]]=x;
    }
    sort(b,b+n);
    for(ll i=0;i<n;i++)
    {
        auto it=find(b,b+n,a[i]);
        cost+=a[i]*m[a[i]];
        ll srs=(it-b)+1;
        while(srs!=n)
        {
            cost+=a[i]*m[b[srs]];
            m[b[srs]]=0;
            srs++;
        }
      /* while(it!=end(b)){
        cost+= a[i]*m[b[distance(b,it)]];
         m[b[distance(b,it)]]=0;
         it++;
       }
       */


            
        
    }
    cout<<cost-1<<endl;

}

}