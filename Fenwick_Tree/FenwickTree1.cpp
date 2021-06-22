#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int BIT[10000];
//indexing is always done from 1
void update(int i,int inc,int N)
{
    while(i<=N)
    {
        BIT[i]+=inc;
        i+=(i&(-i));
    }

}
//sum till ith index
int query(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;

}
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
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
    return 0;
}