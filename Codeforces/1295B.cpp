#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,x;
        cin>>n>>x;

        int arr[n+5];

        string s;
        cin>>s;

        int p= 0;
        int f= 0;

        for( int i=0; i<n; i++ )
        {
            if( s[i]=='0' )
                p++;
            else
                p--;

            arr[i]= p;

            if( p==x )
                f++;
        }

        if( !p and f )
        {
            printf("-1\n");
            continue;
        }
        else if(!p)
        {
            printf("0\n");
            continue;
        }

        int ans= 0;

        if(!x)
            ans++;

        for( int i=0; i<n; i++ )
            if( p>0 and x>=arr[i] and (x-arr[i]+p)%p==0 )
                ans++;
        for( int i=0; i<n; i++ )
            if( p<0 and x<=arr[i] and abs(x-arr[i])%abs(p)==0 )
                ans++;
        printf("%d\n", ans);
    }
}
