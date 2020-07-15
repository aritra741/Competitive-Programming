#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
}arr[1010];

ll sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
             (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    else if(val>0)
        return 2;
    return 0;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;
    cin>>arr[0].x>>arr[0].y;

    arr[n].x= arr[0].x;
    arr[n].y= arr[0].y;

    int cnt= 0;

    for(int i=0;i<n-1;i++)
        if( sign( arr[i],arr[i+1],arr[i+2] )== 2)
            cnt++;

    cout<< cnt <<endl;
}
