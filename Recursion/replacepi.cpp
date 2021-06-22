#include<iostream>
using namespace std;
#define ll long long
void ReplacePi(char a[],int i)
{
    if(a[i]=='\0' || a[i+1]=='\0')
    return;
    if(a[i]=='p' && a[i+1]=='i')
    {
        int j=i+2;
        //push j to the last position
        while(a[j]!='\0')
        {
            j++;
        }
        while(i+2<=j)
        {
            a[j+2]=a[j];
            j--;
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        ReplacePi(a,i+4);

    }
    else
    {
        ReplacePi(a,i+1);
    }
    
}
int main()
{
char a[]="madworldpi";
ReplacePi(a,0);
cout<<a<<endl;
return 0;
}