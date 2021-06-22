#include<iostream>
#include<vector>
#include<map>
#include<set>
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
const int MAX = 26; 
string printRandomString(int n) 
{ 
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % MAX]; 
      
    return res; 
} 
int main() 
{
 

ll t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    ll a[n+2];
    ll maxi=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    a[n]=0;
    a[n+1]=0;
    string s=printRandomString(n);
    map<ll,string> m;
    for(ll i=0;i<=n;i++)
    {
       
        m[a[i]]=s.substring(0,a[i]);
         if(i>0)
        {
        ll len=max(a[i],a[i-1]);
        
        string es=m[a[i]];
        if(es.length()<len && i>0)
        {
            m[a[i]]=m[a[i-1]];
        }
        }


    }
    for(auto goagone:m)
    {
        cout<<goagone.second<<endl;
    }
}


return 0;
   
}