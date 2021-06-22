#include <iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    map<char,ll> m;
    m[s[0]]++;
    for(ll i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
        {
            m[s[i]]++;
        }
        else
        {
            m[s[i]]=1;
        }
    }
    // for(auto go:m)
    // {
    //     cout<<go.first<<" "<<go.second<<endl;
    // }
    set<ll> s;
    for(auto go:m)
    {
        ll x=go.second;
        while(x>=1){
        s.insert((go.first-'a'+1)*x))
        x--;
        }
    }
    
    
  ll t;
  cin>>t;
  while(t--)
  {
   ll n;
   cin>>n;
   if(s.find(n)!=s.end())
   {
       cout<<"Yes"<<endl;
   }
   else
   {
       cout<<"No"<<endl;
   }
   
   
  }
   
   return 0;
}