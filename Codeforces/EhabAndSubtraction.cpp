#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        pq.push(p);
    }

    ll tot= 0;
    int cnt= 0;

    while(cnt!=k)
    {
        if(pq.empty())
        {
            cout<<"0"<<endl;
            cnt++;
        }

        else
        {
            int u= pq.top();
            pq.pop();
            if(u==tot)
                continue;
            cout<<u-tot<<endl;
            tot=u;
            cnt++;
        }
    }


}
