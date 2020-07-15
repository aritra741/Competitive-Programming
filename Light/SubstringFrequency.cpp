#include <bits/stdc++.h>
using namespace std;

int pre[1000007];
string s1,s2;
int cnt;

void precal()
{
    int q= 0;
    cnt= 0;

    for( int i=2;i<s2.size();i++ )
    {
        while( q>0 and s2[q+1]!=s2[i] )
            q= pre[q];
        if( s2[q+1]==s2[i] )
            q++;
        pre[i]= q;
    }
}

int kmp()
{
    memset( pre, 0, sizeof(pre) );
    precal();
    int q= 0;

    for( int i=1;i<s1.size();i++ )
    {
        while( q>0 and s1[i]!=s2[q+1] )
            q= pre[q];
        if( s1[i]==s2[q+1] )
            q++;
        if( q==s2.size()-1 )
            cnt++;
    }

    return cnt;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        cin>>s1>>s2;
        s1= " "+s1;
        s2= " "+s2;

        printf("Case %d: %d\n", t, kmp());
    }
}
