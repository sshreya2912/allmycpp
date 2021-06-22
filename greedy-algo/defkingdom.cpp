#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
#define ll long long
int main()
{
int t;
cin>>t;
while(t--)
{
    int len,height,towers;
    cin>>len>>height>>towers;

    int x,y;
    vector<int> vekx,veky;
    for(int i=0;i<towers;i++)
    {
        cin>>x>>y;
        vekx.push_back(x);
        veky.push_back(y);

    }
    if(len ==0 || height==0)
    {
        cout<<"0"<<endl;
        continue;
    }
    if(towers==0)
    {
        cout<<(len-1)*(height-1)<<endl;
        continue;
    }
   /* for(int i=0;i<towers-1;i++)
    {
        cout<<vekx[i]<<" "<<veky[i]<<endl;

    }*/
   
    sort(vekx.begin(),vekx.end());
    sort(veky.begin(),veky.end());
    int diffx=(vekx[0]-1);
    int diffy=(veky[0]-1);
    int ansx=INT_MIN;
    int ansy=INT_MIN;
    ansx=max(ansx,diffx);
    ansy=max(ansy,diffy);
    for(int i=1;i<towers;i++)
    {
        ansx=max(ansx,vekx[i]-vekx[i-1]-1);
        ansy=max(ansy,veky[i]-veky[i-1]-1);
    }
     ansx=max(ansx,len-vekx[towers-1]);
     ansy=max(ansy,height-veky[towers-1]);

    //cout<<ansx<<" "<<ansy<<endl;
    cout<<(ansx)*(ansy)<<endl;
    




}
return 0;
}