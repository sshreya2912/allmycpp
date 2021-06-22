#include<iostream>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;
int longkarray(int n,int k,int a[])
{
    int pre=0;
    int len=INT_MIN;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        if(pre==k)
        {
          len=max(len,i+1);
        }
        if(m.find(pre-k)!=m.end())
        {
            len=max(len,i-m[pre-k]);
        }
        else
        {
           m[pre]=i;
        }
        
    }
    return len;

}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
cout<<longkarray(n,k,a)<<endl;
    
    
    return 0;
}