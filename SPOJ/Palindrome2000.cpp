#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int tab[5005][5005];
bool vis[5005][5005];
char s[5050];

int rec( int l, int r )
{
    if(l>=r)
        return 0;
    if( vis[l][r] )
        return tab[l][r];

    int q1= inf, q2= inf, q3= inf;

    if( s[l]==s[r] )
        q1= rec(l+1,r-1);
    else
    {
        q2= 1+rec( l+1, r );
        q3= 1+rec( l, r-1 );
    }

    vis[l][r]= 1;

    return tab[l][r]= min( q1, min(q2,q3) );
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    cout<< rec( 0, n-1 ) <<endl;
}
