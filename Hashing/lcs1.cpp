#include<iostream>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;
int lcs(int a[],int n)
{
    set<int> s;
    int x;
    int count=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
       
        if(s.find(a[i]-1)!=s.end())
        {
            continue;
        }
        else
        {
            x=a[i];
            count=0;
            
            while(s.find(x)!=s.end())
            {
              count++;
              x++;
            }
        }
        ans=max(ans,count);
        
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<lcs(a,n);
    return 0;
}