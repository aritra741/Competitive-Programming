#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int num;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0;i<n;i++)
            {
                cin>>num;
                pq.push(num);
            }
        long long ans=0,sum;
        for(int i=1;i<n;i++)
        {
            sum=0;
            int u=pq.top();
            pq.pop();
            if(pq.empty())
                break;
            int v=pq.top();
            pq.pop();
            sum=u+v;
            ans+=sum;
            pq.push(sum);
        }
        cout<<ans<<endl;
    }
}
