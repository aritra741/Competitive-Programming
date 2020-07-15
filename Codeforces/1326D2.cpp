#include<bits/stdc++.h>
#define mx 1000007
using namespace std;

string s;
int d[2][mx];
int n;

void Man(bool T)
{
    for(int i=0,l=0,r=-1; i<n; i++)
    {
        int k=(i>r)?T:min(d[T][l+r-i+!T],r-i+1);
        while(0<=i-k-!T&&i+k<n&&s[i-k-!T]==s[i+k])
            k++;
        d[T][i]=k--;
        if(i+k>r)
        {
            l=i-k-!T;
            r=i+k;
        }
    }
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>s;

        n= s.size();

        Man(0);
        Man(1);

        int i= 0, j= n-1;

        for( ; i<=j; j--,i++ )
            if( s[i]!=s[j] )
            {
                i--;
                j++;
                break;
            }

        if( i>=j )
        {
            cout<<s<<"\n";
            continue;
        }

        int st= i, en= i;
        int ans= 0;
        cout<<"shesh\n";
        for( int k=i+1;k<j;k++ )
        {
            int d1= min(d[0][k]-1, j-k-1);
            int b1= max(d[0][k], k-i-1);

            int x= min( d1, b1 );

            if( 2*x>ans and (k-x==i+1 or k+x==j-1) )
            {
                ans= 2*x, st= k-x, en= k+x;
            }

            int d2= d[1][k]-1;
            int b2= d[1][k]-1;

            int y= min( d2, b2 );

            if( x>y )


            cout<<k<<" "<<baame<<" "<<daane<<endl;

            if( daane-baame+1>ans and ( baame-i<2 or j-daane<2 ) )
                ans= daane-baame+1, st= baame, en= daane;
        }

        for( int k=0;k<=i;k++ )
            cout<<s[k];
        for( int k=st;k<=en and st>i;k++ )
            cout<<s[k];
        for( int k=j;k<n;k++ )
            cout<<s[k];

        cout<<"\n";
    }
}
