#include<bits/stdc++.h>
#define mx 507
using namespace std;

int g[mx][mx], v[mx][mx];
string s[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h,w;
    cin>>h>>w;

    for( int i=1; i<=h; i++ )
        cin>>s[i];

    for( int i=1; i<=h; i++ )
        for( int j=1; j<=w; j++ )
            if( s[i][j-1]=='.' and s[i][j]== '.' )
            {
                g[i][j]++;
                g[i][j+1]--;
                g[i+1][j]--;
                g[i+1][j+1]++;
            }

    for( int i=1; i<=h; i++ )
        for( int j=1; j<=w; j++ )
            if( s[i][j-1]=='.' and s[i+1][j-1]== '.' )
            {
                v[i][j]++;
                v[i][j+1]--;
                v[i+1][j]--;
                v[i+1][j+1]++;
            }

    for( int i=1;i<=h;i++ )
            for( int j=1;j<=w;j++ )
                g[i][j]+= g[i-1][j]+g[i][j-1]-g[i-1][j-1];
    for( int i=1;i<=h;i++ )
            for( int j=1;j<=w;j++ )
                g[i][j]+= g[i-1][j]+g[i][j-1]-g[i-1][j-1];

    for( int i=1;i<=h;i++ )
            for( int j=1;j<=w;j++ )
                v[i][j]+= v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    for( int i=1;i<=h;i++ )
            for( int j=1;j<=w;j++ )
                v[i][j]+= v[i-1][j]+v[i][j-1]-v[i-1][j-1];


    int q;
    cin>>q;

    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int hor= g[c][d-1]-g[a-1][d-1]-g[c][b-1]+g[a-1][b-1];
        int ver= v[c-1][d]-v[a-1][d]-v[c-1][b-1]+v[a-1][b-1];

        cout<<hor+ver<<"\n";
    }
}
