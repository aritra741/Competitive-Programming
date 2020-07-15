#include <bits/stdc++.h>
using namespace std;

int r[100007], pos[100007];

int main()
{
    int a,b,m, dis= 0;
    cin>>a>>b>>m>>r[0];

    memset( pos,-1,sizeof(pos) );
    pos[r[0]]= dis++;

    for( int i=1;i<m+5;i++ )
    {
        r[i]= ( (a*r[i-1])%m+b )%m;

        if( pos[r[i]]!=-1 )
            return cout<< dis-pos[r[i]] <<endl, 0;
        pos[r[i]]= dis++;
    }
}
