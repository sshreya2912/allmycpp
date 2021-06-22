#include <iostream>
using namespace std;
#define M 1e9+7
#define ll long long int 

int main()
{

    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--)
    {
        double a,b,c,p,q,r;
        cin >> a >> b >> c >> p >> q >> r;
        
        
        if(a==p&&b==q&&c==r)
        {
            cout<<"0"<<endl;
            continue;
        }
        else
        {
            // 00 ke else me saare 1 ke cases
            // fir 1 ke else me saare 2 ke cases
            if((a!=p&&b==q && c==r)||(a==p&&b!=q&&c==r)||(a==p&&b==q&&c!=r))
            {
                cout<<"1"<<endl;
                continue;
            }
            else if((a-p==b-q&&b-q==c-r)||(a/p==b/q&&b/q==c/r))
            {
                cout<<"1"<<endl;
                continue;
            }
            else if((a==p&&b-q==c-r)||(a==p&&b/q==c/r)||(b==q&&a-p==c-r)||(b==q&&a/p==c/r)||(c==r&&a-p==b-q)||(c==r&&a/p==b/q))
            {
                cout<<"1"<<endl;
                continue;
            }
            //1 ke saare cases khatam ab 2 ke cases iss else ke andar
            else
            {
                // all cases of 2 aur iske else me seedhe 3 with no check
                double x=(p-q)/(a-b);
                double y=(a*q-b*p)/(a-b);
                if(a*x+y==p&&b*x+y==q&&c*x+y==r)//3mul3add
                {
                    cout<<"2"<<endl;
                    continue;
                }
                else if(p/x-a==q/x-b&&q/x-b==r/x-c)//3add3mul
                {
                    cout<<"2"<<endl;
                    continue;
                }
                else
                {
                    // cout<<"Entered 2d array"<<endl;
                    // cout<<"b/w 2 and 3"<<endl;
                    // add is array of one addition
                    double add[4][30];
                    add[1][1]=a;
                    add[2][1]=b;
                    add[3][1]=c;
                    add[1][2]=b;
                    add[2][2]=a;
                    add[3][2]=a;
                    add[1][3]=c;
                    add[2][3]=c;
                    add[3][3]=b;
                    add[1][4]=b+p-a;
                    add[2][4]=a+q-b;
                    add[3][4]=a+r-c;
                    add[1][5]=c+p-a;
                    add[2][5]=c+q-b;
                    add[3][5]=b+r-c;
                    
                    for(int i=1;i<=3;i++)
                    {
                        if(i==1)
                        for(int j=6;j<=9;j++)
                        {
                            if(j%2==0)
                            add[i][j]=q-add[i][j-4];
                            else 
                            add[i][j]=r-add[i][j-4];
                        }
                        if(i==2)
                        for(int j=6;j<=9;j++)
                        {
                            if(j%2==0)
                            add[i][j]=p-add[i][j-4];
                            else 
                            add[i][j]=r-add[i][j-4];
                        }
                        if(i==3)
                        for(int j=6;j<=9;j++)
                        {
                            if(j%2==0)
                            add[i][j]=p-add[i][j-4];
                            else 
                            add[i][j]=q-add[i][j-4];
                        }
                    }
                    //difference aa gaya ab usko check karna reh raha
                    // multiplication bhi aa jaye fir check karenge dono sath me
                    for(int i=1;i<=3;i++)
                    {
                        if(i==1)
                        for(int j=10;j<=13;j++)
                        {
                            if(j%2==0)
                            add[i][j]=q/add[i][j-4];
                            else 
                            add[i][j]=r/add[i][j-4];
                        }
                        if(i==2)
                        for(int j=10;j<=13;j++)
                        {
                            if(j%2==0)
                            add[i][j]=p/add[i][j-4];
                            else 
                            add[i][j]=r/add[i][j-4];
                        }
                        if(i==3)
                        for(int j=10;j<=13;j++)
                        {
                            if(j%2==0)
                            add[i][j]=p/add[i][j-4];
                            else 
                            add[i][j]=q/add[i][j-4];
                        }
                    }
                    // diff aur mul aa gaya
                    bool f=false;
                    for(int i=1;i<=3;i++)
                    {
                        for(int j=6;j<=9;j++)
                        if(add[i][j]==0)f=true;
                    }
                    if(f){cout<<"2"<<endl;continue;}
                    for(int i=1;i<=3;i++)
                    {
                        if(add[i][7]==add[i][8]||add[i][6]==add[i][7]||add[i][6]==add[i][9])f=true;
                        if(add[i][10]==add[i][11]||add[i][11]==add[i][12]||add[i][10]==add[i][13])f=true;
                    }
                    // for(int i=1;i<=3;i++)
                    // {
                    //     for(int j=1;j<=13;j++)
                    //     cout<<add[i][j]<<" ";
                    //     cout<<endl;
                    // }
                    // continue;
                    if(f){cout<<"2"<<endl;continue;}
                    
                    
                    
                    cout<<"3"<<endl;continue;
                }
                // continue;
            }
        }
    }
    
    return 0;
}