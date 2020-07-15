#include <bits/stdc++.h>
#include <queue>
using namespace std;
priority_queue <int > pq;

int main()
{
    int n,m,temp,sum=0;
    cin>>n>>m;
    for(int j=0;j<n;j++)
    {
        cin>>temp;
        temp=-temp;
        pq.push(temp);
    }
    for(int i=0;i<m;i++)
    {
        temp=pq.top();
        pq.pop();
        if(temp>0)
        sum+=(temp);
    }
    cout<<sum;
}
