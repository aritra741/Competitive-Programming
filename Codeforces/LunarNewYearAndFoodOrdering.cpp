#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<int, pii>
#define cost first
#define num second.first
#define idx second.second
using namespace std;

bool operator < ( piii a, piii b )
{
    if( a.cost==b.cost )
        return a.idx<b.idx;
    return a.cost<b.cost;
}

bool operator == ( piii a, piii b )
{
    return a.cost==b.cost and a.idx==b.idx;
}

priority_queue< piii, vector<piii>, greater<piii> > pq;
ll c[100007], a[100007];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>c[i];

    for(int i=0; i<n; i++)
    {
        piii now;
        now.cost= c[i];
        now.num= a[i];
        now.idx= i;
        pq.push( now );
    }

    while(m--)
    {
        ll tot= 0;
        ll food, quan;
        cin>>food>>quan;
        food--;

        if( a[food]<quan )
        {
            tot+= c[food]*a[food];
            quan-= a[food];
            a[ food ]= 0;

            while( !pq.empty() and !pq.top().num )
                pq.pop();

            while( !pq.empty() and quan )
            {
                piii tp= pq.top();
                pq.pop();
                if( !a[tp.idx] )
                    continue;

                tot+=min(quan, a[tp.idx])*c[tp.idx];
                ll temp= max( 0LL, a[ tp.idx ]-quan );
                quan= max( 0LL, quan- a[ tp.idx ] );
                a[ tp.idx ]= temp;

                piii New;
                New.num= a[tp.idx];
                New.idx= tp.idx;
                New.cost= c[tp.idx];

                if(New.num)
                    pq.push( New );
            }

        }

        else
        {
            tot+= c[ food ]*quan;
            a[food]-= quan;
            quan= 0;

            piii New;
            New.num= a[ food ];
            New.idx= food;
            New.cost= c[ food ];
            pq.push( New );
        }

        if( quan )
            tot= 0;

        cout<< tot <<endl;

    }
}
