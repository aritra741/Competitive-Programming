#include<bits/stdc++.h>
#define ll long long
using namespace std;

deque<int>dq;
int fir[100007], sec[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    int mx= 0, id= 0;

    for( int i=0;i<n;i++ )
    {
        int p;
        cin>>p;

        dq.push_back(p);

        if( p>mx )
            id= i, mx= p;
    }

    int x= dq[0];
    int j= 0;

    while(x!=mx)
    {
        j++;

        int p,q;
        p= dq[0];
        q= dq[1];

        dq.pop_front();
        dq.pop_front();

        dq.push_front( max(p,q) );
        dq.push_back( min(p,q) );

        fir[j]= p;
        sec[j]= q;

        x= dq[0];
    }

    while(q--)
    {
        ll k;
        cin>>k;

        if( k<=j )
            cout<<fir[k]<<" "<<sec[k]<<'\n';
        else
            cout<<mx<<" "<<dq[ (k-j-1)%(n-1)+1 ]<<'\n';
    }
}
