#include<iostream>
#include<unordered_set>
using namespace std;
//program to check if any subarray adds upto 0?
bool checksumzero(int a[],int n)
{
    unordered_set<int> s;
    int pre=0;
    for(int i=0;i<n;i++)
    {
    
        pre+=a[i];
       
        if(pre==0 || s.find(pre)!=s.end())
        {
            return true;
        }
        s.insert(a[i]);
    }
    return false;

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
    
    if(checksumzero(a,n))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    
    

return 0;
}