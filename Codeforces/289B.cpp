#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

int n,m,d;
int arr[10007];

ll ok( ll x )
{
    ll ret= 0;
    for( int i=0;i<n;i++ )
    {
        if( abs(arr[i]-x)%d )
            return inf;
        ret+= abs(arr[i]-x)/d;
    }

    return ret;
}

int main()
{
    cin>>n>>m>>d;
    n*= m;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    ll low= -(arr[0]/d), high= 1e18/d;
    ll ans= -1;

    while( low<high-4 )
    {
        ll mid= (low+high)/2;
        ll val= arr[0]+mid*d;

        ll f1= ok( val );
        ll f2= ok( val+d );

        if( f1<f2 )
            ans= f1, high= mid;
        else if( f1==f2 and f1<inf )
            ans= f1, high= mid;
        else
            low= mid;
    }

    while(low<=high)
    {
        ll f= ok(arr[0]+low*d);

        if( f<ans  )
            ans= f;
        low++;
    }

    if(ans==inf)
        ans= -1;

    cout<< ans <<endl;
}
