#include<bits/stdc++.h>
#define mx 200007
using namespace std;

int nn,pp;
char s[mx], t[mx], ashol[mx];
int arr[mx];
int lps[mx];

bool chk(int x)
{
    int j=0, k=0;

    for( int i=0;i<x;i++ )
        t[arr[i]]= 0;

    for( int i=0;i<pp;i++ )
    {
        if(!t[i])
            continue;
        else if( t[i]==s[j] )
            j++;
    }

    for( int i=0;i<pp;i++ )
        t[i]= ashol[i];

    if(j==nn)
        return 1;
    return 0;
}

int main()
{
    scanf("%s", t);
    scanf("%s", s);

    nn= strlen(s);
    pp= strlen(t);

    for( int i=0;i<pp;i++ )
        ashol[i]= t[i];

    for( int i=0;i<pp;i++ )
        scanf("%d", &arr[i]), arr[i]--;

    int l= 1, r= pp;
    int ans= 0;

    while( r-l>4 )
    {
        int mid= (r+l)/2;

        if( chk(mid) )
            ans= mid, l= mid+1;
        else
            r= mid-1;
    }

    while(l<=r)
    {
        if( chk(l) and l>ans )
            ans= l;
        l++;
    }

    printf("%d\n", ans);
}
