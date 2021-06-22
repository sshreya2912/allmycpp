#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
bool chec_prime(int n)
{
    if(n==1)
    return false;
    if(n==2)
    return true;
    for(int i=2;i*i<n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
void sieve(ll *p)
{
    for(ll i=3;i<=1000000;i+=2)
    {
         p[i]=1;
    }
    for(ll i=2;i<=1000000;i++)
    {
        if(p[i]==1)
        {
            for(ll j=i*i;j<=1000000;j+=i)
            p[j]=0;
        }
    }
    p[0]=p[1]=0;
    p[2]=1;
    ll n=100;
    for(ll i=0;i<=n;i++)
    {
        if(p[i])
        cout<<i<<" ";
    }
}


int main()
{
    cout<<chec_prime(89)<<endl;
    ll p[1000005];
    sieve(p);
    return 0;
}