#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long
int main()
{
   while(cin){
    ll n;
    cin>>n;
    if(n==-1)
    {
        return 0;
    }
    ll a[n];
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n==0)
    {
        ll check=sum/n;
        ll cs=0;
        ll legitneed=0;
        ll legitneed2=0;
        ll ans=INT_MIN;
        for(ll i=0;i<n;i++)
        {
            legitneed2=0;

            ll cs2=0;
             cs+=a[i];
             legitneed+=check;

          for(ll j=i+1;j<n;j++)
          {
              cs2+=a[j];
              legitneed2+=check;  


          }
          ll comp=(min(cs,cs2)==cs?abs(legitneed-cs):abs(legitneed2-cs2));
          ans=max(ans,comp);
          
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
        continue;
    }}
    


    
}