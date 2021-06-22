#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int BIT[10000];
//max query but only prefix
//indexing is always done from 1
void update(int i,int val,int N)
{
    while(i<=N)
    {
        BIT[i]=max(BIT[i],val);
        i+=(i&(-i));
    }

}

int query(int i,int value)
{
    int ans=0;
    while(i>0)
    {
        ans=max(value,BIT[i]);
        i-=(i&(-i));
    }
    return ans;

}
//this code works fine on online compilers

int main()
{
    int n;
    cin>>n;
    //build the bit
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
       update(i,a[i],n);

    }
    //query
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<query(x,a[x])<<endl;
    }
    return 0;
}