#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
}arr[110];

double dist( point a, point b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;

    double tot= 0.0;

    for(int i=1;i<n;i++)
        tot+= dist( arr[i],arr[i-1] );

        cout<<setprecision(6)<<fixed<< tot*k/50.0 <<endl;
}
