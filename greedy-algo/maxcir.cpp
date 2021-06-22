#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include <utility> 
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

bool compare(const pair<ll,ll> &p1,const pair<ll,ll> &p2)
{
    return (p1.second<p2.second);
}
int main() 
{
 
ll t,c,r;
cin>>t;
vector< pair <ll,ll> > v;
for(ll i=0;i<t;i++)
{
   cin>>c>>r;
    v.push_back(make_pair(c-r,c+r));

}
sort(v.begin(),v.end(),compare);
ll res=1;
ll fin=v[0].second;
for(int i=1;i<t;i++)
{
if(v[i].first>=fin)
{
    fin=v[i].second;
    res++;
}
}
cout<<t-res<<endl;



return 0;
   
}