#include <bits/stdc++.h>
#define pii pair<int,int>
#define adj first
#define node second
#define ll long long
using namespace std;

ll con[5294310], mn[25];
priority_queue< pii > pq;
vector<int> ans;

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int p,q;
        cin>>p>>q;

        p--,q--;

        con[p]|=(1<<q);
        con[q]|=(1<<p);
    }

    for(int i=0; i<n; i++)
    {
        int cnt= __builtin_popcount(con[i]);
        mn[i]= cnt;

        pq.push( pii(cnt, i) );
    }

    while(!pq.empty())
    {
        pii u= pq.top();
        pq.pop();

        if( u.adj<mn[u.node] )
            continue;

        bool inside= 0;
        for(int i=0;i<n;i++)
        {
            if( !(con[u.node]&(1<<i)) or i==u.node )
                continue;

            for(int j=0;j<n;j++)
            {
                if( !(con[u.node]&(1<<j)) or i==j )
                    continue;
                if( con[i]&(1<<j) )
                    continue;
                inside= 1;
                con[i]|=(1<<j);
                int temp= __builtin_popcount(con[i]);

                if( temp>mn[i] )
                {
                    mn[i]= temp;
                    pq.push( pii( temp, i ) );
                }
            }
        }

        if(inside)
            ans.push_back(u.node+1);
    }

    cout<< ans.size() <<endl;

    for(int i=0;i<ans.size();i++)
        cout<< ans[i] <<" ";

}
