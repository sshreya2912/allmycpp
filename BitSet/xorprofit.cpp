#include<iostream>
using namespace std;
#define ll long long
ll profitxor(ll x,ll y)
{
    ll xXy=x^y;
    ll digits=0;
    while(xXy>0)
    {
        digits++;
        xXy=xXy>>1;

    }
    ll maxxor=0;
    ll two=1;
    while(digits--)
    {
        maxxor+=two;
        two=two<<1;
    }
    cout<<maxxor<<endl;
}
int main()
{
    ll x,y;
    cin>>x;
    cin>>y;
    profitxor(x,y);

}