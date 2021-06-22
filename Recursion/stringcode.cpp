#include <iostream>

using namespace std;
#define ll long long
void generate_strings(char *c,char *out,ll i,ll j)
{
    if(c[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    ll digit=c[i]-'0';
    char ch=digit+('A'-1);
    out[j]=ch;
    generate_strings(c,out,i+1,j+1);
    if(c[i+1]!='\0')
    {
        ll sec_digit=  c[i+1]-'0';
        ll double_digit= digit*10 + sec_digit;
       
        
        if(double_digit<=26)
        {
             char dchar=double_digit+('A'-1);
             out[j]=dchar;
             generate_strings(c,out,i+2,j+1);
            
        }
    }
    return;
    
    
}

int main()
{
    char c[1000];
     cin>>c;
    char out[1000];
   
    generate_strings(c,out,0,0);
    
   
   
   return 0;
}