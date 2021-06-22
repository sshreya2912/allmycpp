#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int main()
{
    string s;
    string subs;
    cin>>s;
    cin>>subs;
    map<char,bool> ms;
    map<char,bool> msubs;
    for(int i=0;i<subs.length();i++)
    {
       msubs[subs[i]]=0;
    }
    for(int i=0;i<s.length();i++)
    {
       ms[s[i]]=0;
    }
    for(int i=0;i<subs.length();i++)
    {
       
    }
    

}
