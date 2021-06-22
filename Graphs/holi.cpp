#include<iostream>
#include<list>
using namespace std;
#define ll long long

class Graph {
    ll V;
    list<pair<ll, ll> >  *l;
public:
    Graph(ll v) {
        V = v;
        l = new list<pair <ll, ll> > [V];

    }
    void Print(){
        for(int i=0;i<V;i++){
            cout<<i<<" --> ";
            for(auto it:l[i]){
                cout<<it.first<<" "<<it.second<<"\t";
            }
            cout<<endl;
        }
    }
    void addEdge(ll u, ll v, ll cost)
    {
        l[u].push_back(make_pair(v, cost));
        l[v].push_back(make_pair(u, cost));
    }
    ll dfs_helper(ll node, bool *visited, ll *count, ll &ans)
    {
        // cout<<node<<endl;
        visited[node] = true;
        count[node] = 1;
        for (auto nbr_pair : l[node])
        {
            ll nbr = nbr_pair.first;
            ll wt = nbr_pair.second;
            if (!visited[nbr])
            {
                count[node] += dfs_helper(nbr, visited, count, ans);
                ll nx = count[nbr];
                ll ny = V - nx;
                ans += 2 * min(nx, ny) * wt;
                // cout<<ans<<endl;
            }
        }
        return count[node];
    }
//complexity O(N)
    int dfs()
    {
        bool *visited = new bool[V];
        ll *count = new ll[V];
        for (ll i = 0; i < V; i++)
        {
            visited[i] = false;
            count[i] = 0;
        }
        ll ans = 0;
        dfs_helper(0, visited, count, ans);
        return ans;
    }

};
int main()
{

    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    // g.Print();
    cout << g.dfs() << endl;
}