#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
int main()
{
ll n,d;
cin>>n>>d;
ll x;
vector<ll> vec;
for(ll i=0;i<n;i++)
{
    cin>>x;
    vec.push_back(x);

}
sort(vec.begin(),vec.end());
ll ans=0;
for(ll i=1;i<n;i++)
{
    if(abs(vec[i-1]-vec[i])<=d)
    {
        ans++;
        i++;
    }

}
cout<<ans<<endl;
}