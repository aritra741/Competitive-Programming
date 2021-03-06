#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[100007], b[100007];
int n,m;

ll ok( ll mid )
{
    ll f= 0;
    for( int i=0; i<n; i++ )
        if(mid>a[i])
            f+=mid-a[i];
    for( int i=0; i<m; i++ )
        if(b[i]>mid)
            f+=b[i]-mid;

    return f;
}


int main()
{
    scanf("%d %d", &n, &m);
    int mx= 0;

    for( int i=0; i<n; i++ )
        scanf("%d", &a[i]);
    for( int i=0; i<m; i++ )
        scanf("%d", &b[i]);

    int l= 1, r= 1e9;
    ll ans= 1e18;

    while (r-l>5)
    {
        int mid= (l+r)/2;
        ll ok1= ok(mid), ok2= ok(mid+1);

        if ( ok1<ok2 )
        {
            r= mid;
            if(ok1<ans)
                ans= ok1;
        }
        else
        {
            l= mid;
            if(ok2<ans)
                ans= ok2;
        }
    }

    while(l<=r)
    {
        ll now= ok(l);
        if( now<ans )
            ans=now;
        l++;
    }

    printf("%lld\n", ans);
}
