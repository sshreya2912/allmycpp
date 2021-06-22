#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
//only arrays sum up to 0 whose cumulative frequency array is 0(thus upto that index original array)
//or the ones with same element in cumulative sum array (a[i],a[j]] (inclusive, exclusive)
int lengthofls(int array[],int n)
{
    unordered_map<int,int> m;
    int pre=0;
    int len=INT_MIN;
    for(int i=0;i<n;i++)
    {
       pre+=array[i];
       if(pre==0)
       {
          len=max(len,i+1);
       }
       if(m.find(pre)!=m.end())
       {
           len=max(len,m[pre]);
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
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<lengthofls(array,n)<<endl;

return 0;
}