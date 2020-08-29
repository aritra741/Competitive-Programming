#include <bits/stdc++.h>
#define pid pair<int,double>
#define inf INT_MAX
using namespace std;

map< pid, int > dp;
map< pid, int > vis;
int n, now;
int arr[110];
double prob[110];
double lim;

int rec( int i, double p )
{
    if(p>lim)
        return -inf;
    if(i>=n)
        return 0;
    if( vis[ pid( i,p ) ]==now )
        return dp[ pid(i,p) ];

    int q1= rec( i+1, p );
    int q2= arr[i]+rec( i+1, p+(1.00-p)*prob[i] );

    vis[ pid( i,p ) ]=now;

    //cout<<i<<" "<<q1<<" "<<q2<<" "<<p<<endl;
    return dp[ pid( i, p ) ]= max( q1, q2 );
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        now++;
        cin>>lim>>n;

        for(int i=0; i<n; i++)
            cin>>arr[i]>>prob[i];

        //cout<<lim<<endl;
        cout<<"Case "<<t<<": "<< rec( 0, 0.00 ) <<endl;
        dp.clear();
        vis.clear();
    }
}
