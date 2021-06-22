#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
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
     ll dist[n],petrol[n];
     ll checker=0;
    for(ll i=0;i<n;i++)
    {
        cin>>dist[i]>>petrol[i];
        checker+=petrol[i];
    }
    ll l,p;
    cin>>l>>p;
    checker+=p;
    if(checker-l<=0)
    {
        cout<<"-1"<<endl;
        continue;
    }
    else if(p>=l)
    {
        cout<<"0"<<endl;
        continue;
    }
    else{
    for(ll i=0;i<n;i++)
    {
        m[l-dist[i]]=petrol[i];
    }
    ll newd[n+1],newp[n+1];
    int it=0;

   for(auto go:m)
    {
        //cout<<go.first<<" "<<go.second<<endl;
        newd[it]=go.first;
        newp[it]=go.second;
        it++;

    }
    ll curpet=p;
    ll ans=0;
    newd[it]=l;
    
    newp[it]=p;

    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            curpet=curpet-newd[i];
        }
        else{
        curpet=curpet-(newd[i+1]-newd[i]);
        }
        if(curpet<(newd[i+1]-newd[i]))
        {
            curpet+=newp[i];
            ans++;

        }
    }
    cout<<ans<<endl;
    }

}
}