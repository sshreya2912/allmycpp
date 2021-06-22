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
     }
     int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=query(a[i]-1);
        update(a[i],1,n);

    }
    cout<<ans<<endl;
    
    return 0;
}