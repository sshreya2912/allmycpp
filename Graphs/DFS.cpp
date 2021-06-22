#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > l;
    public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, map<T,bool> &visited)
    {
        cout<<src<<" ";
        visited[src]=true;
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool> visited;
        for(auto go:l)
        {
            visited[go.first]=false;
        }
        dfs_helper(src,visited);

    }

};
int main()
{
    
    Graph<int> g;
    
    g.addEdge(1,2);
    g.addEdge(2,3);
    
    g.dfs(2);
    return 0;
}