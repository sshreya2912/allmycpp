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

    public:
    void AddEdge(T x,T y)
    {
        l[x].push_back(y);
       // l[y].push_back(x);

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
        for(auto gone:l)
        {
            T node=gone.first;
            cout<<"DISTANCE of"<<node<<" from source "<<distance[node]<<endl;
        }
       
    }

};
int main() 
{
    Graph<ll> g;
 ll board[50];
 ll ladders;
 ll snakes;
 cin>>ladders;
 ll s,e;
 for(ll i=0;i<ladders;i++)
 {
     cin>>s>>e;
     board[s]= e-s;
 }
 cin>>snakes;
 for(ll i=0;i<snakes;i++)
 {
     cin>>s>>e;
     board[s]=e-s;
 }
 for(ll i=0;i<=36;i++)
 {
     for(ll dice=1;dice<=6;dice++)
     {
         ll j;
         j+=i;
         j+=dice;
         j+=board[j];
         if(j<=36){
         g.AddEdge(i,j);
         }
         
     }
 }
 g.AddEdge(36,36);





return 0;
   
}