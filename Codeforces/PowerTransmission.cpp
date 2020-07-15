#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
} arr[55];

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

int main()
{
    int n;
    cin>>n;

    for( int i=0; i<n; i++ )
    {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }

    int cnt= 0;
    for( int i=0; i<n; i++ )
        for( int j=i+1; j<n; j++ )
            for( int k=0; k<n; k++ )
                for( int l=k+1; l<n; l++ )
                {
                    if( (k==i and j==l) or (i==l and j==k) )
                        continue;
                    int val1= sign( arr[i], arr[j], arr[k] );
                    int val2= sign( arr[i], arr[j], arr[l] );
                    int val3= sign( arr[k], arr[l], arr[i] );
                    int val4= sign( arr[k], arr[l], arr[j] );

                    if( val1!=val2 and val3!=val4 )
                        cnt++;
                }

    cout<< cnt <<endl;
}
