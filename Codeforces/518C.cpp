#include<bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

deque<int>dq[mx];
int mark[mx], koi[mx];

int main()
{
    int n,k,m;
    cin>>n>>k>>m;

    int x;

    for( int i=1;i<=n;i++ )
        cin>>x, mark[x]= (i+m-1)/m, dq[(i+m-1)/m].push_back(x), koi[x]= dq[(i+m-1)/m].size()-1;

    ll ans= 0;

    for( int i=1;i<=k;i++ )
    {
        cin>>x;
        int y= mark[x];

        ans+= y;

        if(koi[x])
        {
            swap(dq[y][koi[x]], dq[y][koi[x]-1]);

            koi[x]--;
            koi[dq[y][koi[x]+1]]++;
        }
        else if( y>1 )
        {
            int a= dq[y-1][ dq[y-1].size()-1 ];
            dq[y-1][ dq[y-1].size()-1 ]= x;
            dq[y][0]= a;
            koi[x]= dq[y-1].size()-1;
            mark[x]= y-1;
            koi[ dq[y][0] ]= 0;
            mark[ dq[y][0] ]= y;
        }
    }

    cout<< ans <<endl;
}
