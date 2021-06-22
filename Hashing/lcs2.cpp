#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;
void lcs(int a[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        if(m.find(a[i]-1)!=m.end() && m.find(a[i]+1)!=m.end())
        {
            int len1=m[a[i]-1];
            int len2=m[a[i]+1];
            int cur=m[a[i]];
            m[a[i]]=len1+len2+1;
            m[a[i]-1]=cur-len1;
            m[a[i]+1]=cur+len2;
        }
        else if(m.find(a[i]-1)!=m.end())
        {
            int len1=m[a[i]-1];
            int cur=m[a[i]];
             m[a[i]]=len1+1;
             m[a[i]-1]=cur-len1;


        }
        else if(m.find(a[i]+1)!=m.end())
        {
             int len2=m[a[i]+1];
             int cur=m[a[i]];
             m[a[i]]=len2+1;
             m[a[i]+1]=cur+len2;

        }
        else
        {
            m[a[i]]=1;
        }
        


    }
    int low=INT_MAX;
        int high=INT_MIN;
        int lowlen=INT_MAX;
        int highlen=INT_MIN;
    for(auto gee:m)
    {
       high=max(high,gee.second);

        
    }
    for(auto gee:m)
    {
       if(gee.second==high)
       {
           highlen=max(highlen,gee.first);
           lowlen=min(lowlen,gee.first);
       }
        
    }
    for(int i=lowlen;i<=highlen;i++)
    {
        cout<<i<<" ";
    }



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
    lcs(a,n);
    return 0;
}