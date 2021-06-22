#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;


#define MOD 1000000007

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int cost[100000];
template<typename T>
class Graph{
    map<T,list<T> > l;

    public:
    void AddEdge(T x,T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }
    vector<int> BFS(T src,T dest)
    {
        vector<T> v;
        queue<T> q;
        map<T,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
         T node= q.front();
          q.pop();
       // cout<<node<<" ";
        v.push_back(cost[node]);
        if(node==dest)
        {
            return v;
        }
        for(auto nbr:l[node])
        {
            if(!visited[nbr])
            {
                q.push(nbr);
                visited[nbr]=true;
            }
        }
        }
       
    }

};
int main() 
{
    FIO

 Graph<int> g;

int n,q;
cin>>n>>q;
for(int i=0;i<n;i++)
{
    cin>>cost[i];
}
int x,y;
for(int i=0;i<n-1;i++)
{
    cin>>x>>y;
    g.AddEdge(x-1,y-1);
}

int n1,n2;
vector<int> v1;
vector<int> v2;
while(q--)
{

    cin>>n1>>n2;
vector<int> v1=g.BFS(0,n1-1);
vector<int> v2=g.BFS(0,n2-1);


for(auto go:v1)
{
    cout<<go<<" ";

}
cout<<endl;
for(auto go:v2)
{
    cout<<go<<" ";
}
}






return 0;
   
}