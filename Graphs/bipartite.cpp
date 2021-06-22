#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define N 100005
bool odd_cycle=0;
ll visited[N]={0};
vector<ll> gr[N];

void dfs(ll cur,ll par, ll col)
{
   visited[cur]=col;  
    for(auto child: gr[cur])
    {
       if(visited[child]==0)
       {
           // we are alternating bw 1 and 2
           dfs(child,cur,3-col);
       }
       else if(child!=par && visited[child]==col)
       {
           odd_cycle=1;
       }

    }
    return;

}
bool solve()
{

    ll i,j,k,n,m;
    ll ans=0;
    ll cnt,sum;
    cin>>n>>m;
    //n is the no of nodes m is number of connections
    ll x,y;
    for(ll i=0;i<m;i++)
    {
       cin>>x>>y;
       gr[x].push_back(y);
       gr[y].push_back(x);
    }
     dfs(1,0,1);
     if(odd_cycle)
     return true;
     else
     {
         return false;
     }
     
   


}
int main()
{
    if(solve())
    {
        cout<<"Yes, a bipartite graph"<<endl;

    }
    else
    {
        cout<<"Nope bruh"<<endl;
    }
    

    return 0;
}