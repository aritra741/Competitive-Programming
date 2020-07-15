#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

map<pii,int> mp;
int x[1010], y[1010], a[1010], b[1010];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];

    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];

    int Tx, Ty;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[ pii( x[i]+a[j], y[i]+b[j] ) ]++;

            if( mp[ pii( x[i]+a[j], y[i]+b[j] ) ]==n )
            {
                Tx= x[i]+a[j],
                Ty= y[i]+b[j];
                break;
            }
        }
    }

    cout<< Tx <<" "<< Ty <<endl;
}
