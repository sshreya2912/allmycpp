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
struct node{
    int number;
    int cost;
};
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
        map<T,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
         T node= q.front();
          q.pop();
        cout<<node<<" ";
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
 Graph<node> g;
 g.AddEdge(0,1);
 //g.AddEdge(0,1);
 g.AddEdge(2,1);
 g.AddEdge(2,3);
 g.AddEdge(3,4);
 g.AddEdge(4,5);
 g.BFS(0);





return 0;
   
}