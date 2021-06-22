#include <iostream>
#include<unordered_map>
#include<utility>
#include<list>
#include<map>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int> > >   m;
public:
     void addEdge(T u,T v,int dist, bool bidir=true)
     {
        m[u].push_back(make_pair(v,dist));
        if(bidir)
        m[v].push_back(make_pair(u,dist));

         
     }
     void printAdj()
     {
         //print the above made adj list
         for(auto go:m)
         {
            cout<<go.first<<"->";
            for(auto goa:go.second)
            {
               cout<<"{"<<goa.first<<","<<goa.second<<"}";
            }
            cout<<endl;
         }
     }
     void dijkstraSSSP(T src)
     {
        //make a map
        map<T,int> dist;
        for(auto go:m)
        {
          dist[go.first]=INT_MAX;
        }
        //make a set
        set<pair< int, T> > s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
           auto p=*(s.begin());
           T node=p.second;
           int nodeDist=p.first;
           s.erase(s.begin());
           for(auto childPair:m[node])
           {
              if(nodeDist+ childPair.second <dist[childPair.first])
              {
                 //updation not possible in a set
                 T dest=childPair.first;
                 auto f=s.find(make_pair(dist[dest],dest));
                 if(f!=s.end())
                 {
                    s.erase(f);
                 }
                 //insert the new pair
                 dist[dest]=nodeDist+ childPair.second ;
                 s.insert(make_pair(dist[dest],dest));
              }
           }
           

        }
      for(auto d:dist)
      {
         if(d.first!=src)
         cout<<d.second<<" ";
      }
         
     }
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n,m;
      cin>>n>>m;
      Graph<int> g;
      int x,y,d;
      for(int i=0;i<m;i++)
      {
         cin>>x>>y>>d;
         g.addEdge(x,y,d);
      }
      int src;
      cin>>src;
       g.dijkstraSSSP(src);
       cout<<endl;
   }

  /* Graph<int> g;
  
    g.addEdge(0,2,1);
    g.addEdge(0,4,7);
    g.addEdge(0,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
   // g.printAdj();
   
  */ 
   
   return 0;
}