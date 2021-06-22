#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int s,vector<vector<int> > adj,int n)
{
    //vector<vector<int> > adj;
   // int n;
   // int s;
    queue<int> q;
    vector<bool> used(n);
    vector<int> p(n),d(n);
    q.push(s);
    used[s]=true;
    p[s]=-1;
    //d[s]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto u:adj[v])
        {
            if(!used[u]){
            used[u]=true;
            q.push(u);
            d[u]=d[v]+1;
            p[u]=v;
            }
            

        }

    }
    for(auto go:d)
    {
        cout<<go<<" ";
    }
    
    return;

}
int main()
{
    vector<vector<int> > adj(6);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[4].push_back(5);
    adj[3].push_back(5);
    
bfs(0,adj,6);

}