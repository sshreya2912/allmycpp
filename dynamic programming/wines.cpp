#include<iostream>
using namespace std;
int profit(int ar[],int i,int j,int y,int dp[][100])
{
	
	if(i>j)
		return 0;
	if(dp[i][j]!=0)
		return dp[i][j];
	int op1=ar[i]*y + profit(ar,i+1,j,y+1,dp);
	int op2=ar[j]*y + profit(ar,i,j-1,y+1,dp);
	int ans=max(op1,op2);
	return dp[i][j]=ans;
	
}
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int ar[]={2,3,5,1,4};
	int n=sizeof(ar)/sizeof(int);
	
	int dp[100][100];
	int y=1;
	int cost=profit(ar,0,n-1,y,dp);
	cout<<cost<<endl;
}


