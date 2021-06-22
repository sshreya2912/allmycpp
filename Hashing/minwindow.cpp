#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
string findwindow(string s, string p)
{
int sizes=s.length();
int sizep=p.length();
if(sizep>sizes)
{
    return "None";
}
int FS[256];
int FP[256];
for(int i=0;i<sizep;i++)
{
   char ch=p[i];
   FP[ch]++;
}
int cnt=0;
int start=0;
int min_len=INT_MAX;
int start_idx=-1;
for(int i=0;i<sizes;i++)
{
    char ch=s[i];
    FS[ch]++;
    //checking if matched or not
    if(FP[ch]!=0 && FS[ch]<=FP[ch])
     {
        cnt++;
     }
     // if match shrink for smallest window
     if(cnt==sizep)
     {
         char temp=s[start];
         while(FP[temp]==0 || FS[temp]>FP[temp])
         {
             FS[temp]--;
             start++;
             temp=s[start];
         }
         int window_len=i-start+1;
         if(window_len<min_len)
         {
             min_len=window_len;
             start_idx=start;
         }

     }
}
if(start_idx==-1)
return "None";
string ans=s.substr(start_idx,min_len);
return ans;

}
int main()
{
    string s;
    string p;
    cin>>s;
    cin>>p;
    cout<<findwindow(s,p)<<endl;
    return 0;
}