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
char word[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int digitword(int n)
{
    if(n==0)
    return 0;
    
    digitword(n/10);
    cout<<word[n%10]<<" ";

}

int main() 
{
 

int n;
cin>>n;
digitword(n);


return 0;
   
}