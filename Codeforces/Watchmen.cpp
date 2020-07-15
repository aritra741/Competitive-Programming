#include <bits/stdc++.h>
#define ll long long
#define mx 200007
#define eps 1e-7
using namespace std;

struct point
{
    ll x,y;
} arr[mx];

bool cmp( point a, point b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool cmp2( point a, point b )
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

ll sum( ll n )
{
    return (n*(n+1))/2;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i].x>>arr[i].y;

    sort(arr,arr+n,cmp);
    ll cnt= 0;
    int j= 1;
    ll samex= 0;

    for(int i=0; i<n; i=j)
        for(j=i+1; j<n; j++)
        {
            if( arr[i].x==arr[j].x )
                cnt++;
            else
            {
                samex+= sum(cnt);
                cnt= 0;
                break;
            }
        }

    samex+=sum(cnt);

    sort(arr,arr+n,cmp2);
    j= 1;
    ll samey= 0;
    cnt= 0;

    for(int i=0; i<n; i=j)
        for(j=i+1; j<n; j++)
        {
            if( arr[i].y==arr[j].y )
                cnt++;
            else
            {
                samey+= sum(cnt);
                cnt= 0;
                break;
            }
        }

    samey+=sum(cnt);

    j= 1;
    ll bothsame= 0;
    cnt= 0;

    for(int i=0; i<n; i=j)
        for(j=i+1; j<n; j++)
        {
            if( arr[i].x==arr[j].x and arr[i].y==arr[j].y )
                cnt++;
            else
            {
                bothsame+= sum(cnt);
                cnt= 0;
                break;
            }
        }

    bothsame+=sum(cnt);

    cout<< samex+samey-bothsame <<endl;
}

