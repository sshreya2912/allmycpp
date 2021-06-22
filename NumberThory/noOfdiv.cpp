#include <iostream>
#include<vector>

using namespace std;
vector<int> primeSieve(int *p,int n)
{
    p[0]=p[1]=0;
    p[2]=1;
    //marking all the odd numbers as prime-iniialisation
    for(int i=3;i<=n;i=i+2)
    {
        p[i]=1;
    }
    //seive to mark all non prime as 0
    for(int i=3;i<=n;i+=2)
    {
        if(p[i])
        {
            for(long long int j=i*i;j<=n;j+=2*i)
            p[j]=0;
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(p[i])
        primes.push_back(i);
    }
    return primes;
}
int nOD(int m,vector<int> &primes)
{
    int i=0;
   
    int p=primes[0];
   int cnt;
    int ans=1;
    while(p*p<=m)
    {
        if(m%p==0)
        {
            cnt=0;
            while(m%p==0)
            {
                m=m/p;
                cnt++;
            }
            ans=ans*(cnt+1);
        }
        //go to the next position
        i++;
        p=primes[i];
    }
    if(m!=1)
    ans=ans*2;
    
    
    return ans;
    
}

int main()
{
     int n=1000000;
     int p[n];
   for(int i=0;i<=n;i++)
   {
       p[i]=0;
   }
  
  vector<int> primes= primeSieve(p,100);
  int ans =nOD(10,primes);
  
  cout<<"no of div of 10 are "<<ans<<endl;
   
   
   return 0;
}