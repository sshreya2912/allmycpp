#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<list>
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
class Graph{
    int V;
    //Array of List
    list<int> *l;
    public:
    Graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int x,int y)
    {
          l[x].push_back(y);
          l[y].push_back(x);
    }
    void printAdjList()
    {
        //iterates all over vertices
        for(int i=0;i<V;i++)
        {
            cout<<"Vertex "<<i<<"->";
            for(int nbr:l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
            
        }
    }
};

int main() 
{
 
Graph g(4);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(2,3);
g.addEdge(1,2);
g.printAdjList();


return 0;
   
}