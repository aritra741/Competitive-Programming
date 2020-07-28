#include<bits/stdc++.h>
using namespace std;

int m,n;
vector<int>v;
bool dp[4007][2007];
int vs[4007][2007];
int pp;

bool rec( int i, int x )
{
    if(x>n)
        return 0;
    if( x==n )
        return 1;
    if( i>=m )
        return 0;
    if( vs[i][x]==pp )
        return dp[i][x];

    bool q1= rec( i+1, x );
    bool q2= rec( i+1, x+v[i] );

    vs[i][x]= pp;

    return dp[i][x]= q1|q2;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        pp++;
        cin>>n;

        int arr[2*n+5];
        bitset<4007>bs;

        for( int i=0;i<2*n;i++ )
            cin>>arr[i], bs[ arr[i] ]= 1;

        reverse( arr, arr+2*n );
        v.clear();
        int cnt= 0;

        for( int i=0;i<2*n;i++ )
        {
            cnt++;
            if( bs._Find_first()==2*n-arr[i]+1 )
                v.push_back(cnt), cnt= 0;
            bs[2*n-arr[i]+1]= 0;
        }

        if(cnt)
            v.push_back(cnt);

        m= v.size();

        bool ans= rec( 0, 0 );

        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
