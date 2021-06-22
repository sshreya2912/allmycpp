#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<climits>

using namespace std;

typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

template<typename T>
class Graph{
    map<T,list<T> > l;

    public:
    void AddEdge(T x,T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);

    }
    void BFS(T src)
    {
        queue<T> q;
        map<T,ll> distance;

        q.push(src);
        //visited[src]=true;

        for(auto goa:l)
        {
            T node=goa.first;
            distance[node]=INT_MAX;
        }
        distance[src]=0;

        while(!q.empty()){
         T node= q.front();
          q.pop();
        //cout<<node<<" ";
        for(auto nbr:l[node])
        {
            if(distance[nbr]==INT_MAX)
            {
                q.push(nbr);
                distance[nbr]=distance[node]+1;
            }
        }
        
        }
       /* for(auto gone:l)
        {
            T node=gone.first;
            cout<<"DISTANCE of"<<node<<" from source "<<distance[node]<<endl;
        }
        */
       for(auto gone:l)
       {
           T node=gone.first;
           if(6*distance[node]==6)
           {
               cout<<"6 ";
           }
           else
           {
               cout<<"-1 ";
           }
           
       }
       
    }

};
int main() 
{
ll t;
cin>>t;
while(t--)
{
Graph<ll> g;
ll n,e;
cin>>n>>e;
ll u,v;
for(ll i=0;i<e;i++)
{
    cin>>u>>v;
    g.AddEdge(u,v);
}
ll s;
cin>>s;
g.BFS(s);
cout<<endl;

}

 //Graph<ll> g;
 //g.AddEdge(0,1);
 //g.AddEdge(0,1);
 //g.AddEdge(2,1);
 //g.AddEdge(2,3);
 //g.AddEdge(3,4);
 //g.AddEdge(4,5);
 //g.AddEdge(3,0);
 //g.BFS(0);





return 0;
   
}