#include <bits/stdc++.h>
#define pii pair < int, int >
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        int n,m;
        cin>>n>>m;
        deque < pii > dq;
        priority_queue < pii > pq;
        int t;
        for(int j=0;j<n;j++)
        {
            cin>>t;
            dq.push_back( pii(t, j) );    ///This is very important
            pq.push( pii(t, j) );
        }
        int cnt=0;
        while(1)
        {

            pii u=dq.front();
            pii p=pq.top();
//            cout<<u.first<<" "<<p.first<<" "<<u.second<<endl;
            if(p.first>u.first)
            {
                dq.pop_front();
                dq.push_back(u);
            }
            else
            {
                cnt++;
                if(p.first==u.first)
                    pq.pop();
                dq.pop_front();
                if(u.second==m)
                    break;
            }
        }
        cout<<cnt<<endl;

    }
}
