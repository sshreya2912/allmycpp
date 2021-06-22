#include<iostream>
#include<algorithm>
using namespace std;
float square_root(int n)
{
    int s=0;
    int e=n;
    float ans=-1;
    while(s<=e)
    {
     int mid=(s+e)/2;
     if(mid*mid==n)
     {
         return mid;
     }
     else if(mid*mid<n)
     {
         ans=mid;
         s=mid+1;
     }
     else
     {
         e=mid-1;
     }
     
    }
    //floating part by brute force
   
float inc=0.1;
int p=3;
for(int i=0;i<p;i++)
{
    while((ans*ans)<=n)
    {
      ans+=inc;
    }
    ans=ans-inc;
    inc=inc/10;
    

}
    return ans;
}
int main()
{
    //take input of an integer n 
    int n;
    cin>>n;
    //call the function
    cout<<square_root(n)<<endl;


}