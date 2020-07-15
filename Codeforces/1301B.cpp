#include<bits/stdc++.h>
#define ll long long
using namespace std;

int arr[100007];
int n;

ll ok( int x )
{
    ll ret= 0;

    for( int i=0;i<n-1;i++ )
    {
        ll p= (arr[i]<0)?x:arr[i];
        ll q= (arr[i+1]<0)?x:arr[i+1];

        ret= max(ret, llabs( p-q ));
    }

    return ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
            scanf("%d", &arr[i]);

        int l= 0, r= 1000000000;
        int ans= 1000000000;
        ll val= 1e18;

        while(r-l>5)
        {
            int mid= (r+l)/2;

            ll f1= ok(mid);
            ll f2= ok(mid+1);

            if( f1<=f2 )
            {
                if( f1<val )
                    ans= mid, val= f1;
                r= mid;
            }
            else
                l= mid;
        }

        while(l<=r)
        {
            ll f= ok(l);
            if( f<val )
                val= f, ans= l;
            l++;
        }

        printf("%lld %d\n", val, ans );
    }
}
