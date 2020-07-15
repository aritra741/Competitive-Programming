#include<bits/stdc++.h>
using namespace std;

int deg[100007];

int main()
{
    int n;
    double s;
    cin>>n>>s;

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        deg[p]++;
        deg[q]++;
    }

    double cnt= 0.0;
    for( int i=1;i<=n;i++ )
        if( deg[i]==1 )
            cnt= cnt+1.0;

    cout<<setprecision(10)<<fixed<< (s*2.0)/cnt <<endl;
}
