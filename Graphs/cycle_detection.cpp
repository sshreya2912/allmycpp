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
    int nodes;
    public:
    Graph(int n){
        nodes = n;

    }
    void AddEdge(T x,T y,bool directed=true)
    {
        l[x].push_back(y);
        if(!directed){
         l[y].push_back(x);
        }
        

    }
    bool cycle_helper(bool *visited,int node,int parent)
    {
        visited[node]=true;
        for(auto nbr:l[node])
        {
            if(!visited[nbr])
            {
                bool gotcycle=cycle_helper(visited,nbr,node);
                if(gotcycle)
                return true;
            }
            else if(nbr!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool contains_cycle()
    {
        bool visited[nodes];
        for(ll i=0;i<nodes;i++)
        {
            visited[i]=false;
        }
        return cycle_helper(visited,0,-1);
    }

};
int main() 
{
 Graph<int> g(6);
 g.AddEdge(0,1);
 
 g.AddEdge(1,2);
 g.AddEdge(2,3);
 g.AddEdge(3,4);
 g.AddEdge(4,5);
 //g.AddEdge(5,0);
 //g.BFS(0);

if(g.contains_cycle())
{
    cout<<"CYCLIC "<<endl;
}
else
{
    cout<<"NO"<<endl;
}




return 0;
   
}
