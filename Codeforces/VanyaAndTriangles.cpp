#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
} p[2007];

int sign( point p, point q, point r )
{
    int val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return -1;
    if(val>0)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;

    int cnt= 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if( sign( p[i],p[j],p[k] ) )
                    cnt++;
    cout<< cnt <<endl;
}
