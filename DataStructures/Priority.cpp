#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > pq;
    //for without comparator priority_queue<int> pq; -max pq
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        pq.push(no);//complexity of push operation is O(log N)
        
    }
    //removing elements from the heap
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
        //pop removes the topmost element
    }

    return 0;
}