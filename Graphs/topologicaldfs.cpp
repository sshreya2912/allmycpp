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
      //  l[y].push_back(x);
    }
    void dfs_helper(T src, map<T,bool> &visited,list<T> &ordering )
    {
        //cout<<src<<" ";
        visited[src]=true;
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);//this determines the topological order
       

    }
    void dfs()
    {
        map<T,bool> visited;
        list<T> ordering;
        for(auto go:l)
        {
            visited[go.first]=false;
        }
        for(auto node:l)
        {
          if(visited[node.first]==false)
          {
              dfs_helper(node.first,visited,ordering);
          }
        }
         for(auto go:ordering)
        {
            cout<<go<<" ";
        }
        cout<<endl;
        //dfs_helper(src,visited);

    }

};
int main()
{
    
    Graph<int> g;
    
    g.addEdge(1,2);
    g.addEdge(2,3);
    
    g.dfs();
    return 0;
}