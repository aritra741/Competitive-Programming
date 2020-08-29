#include <bits/stdc++.h>
#define ll long long
using namespace std;

char s[32],t[32];
int lcs[32][32];
int visLcs[32][32];
ll distinct[70][32][32];
int visdist[70][32][32];
int vs1= 1, vs2= 1;

int rec1( int m, int n )
{
    if( n<0 or m<0 )
        return 0;
    if( visLcs[m][n]==vs1 )
        return lcs[m][n];

    int q1= 0, q2= 0;
    if( s[m]==t[n] )
        q1= 1+ rec1( m-1, n-1 );
    else
    {
        q1= rec1( m-1, n );
        q2= rec1( m, n-1 );
    }

    visLcs[m][n]= vs1;

    return lcs[m][n]= max( q1, q2 );
}

ll rec2( int l, int a, int b )
{
    if( !l )
    {
        if( !a and !b )
            return 1;
        return 0;
    }

    if( visdist[l][a][b]==vs2 )
        return distinct[l][a][b];

    ll q1= 0, q2= 0, q3= 0;

    if(a<0)
        q1= rec2( l-1, a, b-1 );
    else if(b<0)
        q1= rec2( l-1, a-1, b );
    else if( s[a-1]==t[b-1] )
        q1= rec2( l-1, a-1, b-1 );
    else
    {
        q1= rec2( l-1, a, b-1 );
        q2= rec2( l-1, a-1, b );
    }

    visdist[l][a][b]= vs2;

    return distinct[l][a][b]= q1+q2;
}


int main()
{
    int tc;
    cin>>tc;

    for(int c=1; c<=tc; c++)
    {
        scanf("%s", s);
        scanf("%s", t);

        printf("Case %d: ", c);
        int slen= strlen(s);
        int tlen= strlen(t);
        int l= rec1( slen-1, tlen-1 );
        l= slen+tlen-l;
        printf("%d ", l);
        printf("%lld\n", rec2( l, slen, tlen ));

        vs1++,vs2++;
    }
}
