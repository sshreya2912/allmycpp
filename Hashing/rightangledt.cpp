#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;
// given various points on a cartesian plane find the number of right angled triangles that can be made

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > obj;
    int x,y;
    unordered_map<int,int> xaxes;
    unordered_map<int,int> yaxes;
    for(int i=0;i<n;i++)
    {
      cin>>x>>y;
      obj.push_back(make_pair(x,y));
      xaxes[x]++;
      yaxes[y]++;


    }
    int ans=0;
    for(auto go:obj)
    {
        if(xaxes[go.first]>1 && yaxes[go.second]>1)
       ans+= (xaxes[go.first]-1)*(yaxes[go.second]-1);
    }
    cout<<ans<<endl;
    
    return 0;
}