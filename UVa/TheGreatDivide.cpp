#include <bits/stdc++.h>
#define mx 1007
#define ll long long
using namespace std;

struct point
{
    ll x,y;
} base;

vector<point> points;

int Size;

bool operator == (point a, point b)
{
    return a.x==b.x and a.y==b.y;
}

int area( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp( const point&a, const point&b )
{
    int pos= area( base, a, b );

    if(pos==0)
    {
        ll d1= dist( base, a );
        ll d2= dist( base, b );

        return d1>d2;
    }

    return pos==2;
}

bool cmp2( const point&a, const point&b  )
{
    ll d1= dist( base, a );
    ll d2= dist( base, b );

    return d1<d2;
}

vector<point> Hull( int n )
{
    vector<point> ans(mx);

    int l=0;

    for(int i=1; i<n; i++)
        if( points[i].x<points[l].x or( points[i].x==points[l].x and points[i].y<points[l].y ))
            l= i;
    base= points[l];

    sort( points.begin(), points.begin()+n, cmp );

    int cnt= 1;

    for(int i=0; i<n-1; i++)
    {
        if( area( base, points[i], points[i+1] )!=0 )
            break;
        cnt++;
    }

    sort( points.begin(), points.begin()+cnt, cmp2 );

    points.erase( unique(points.begin(), points.end()), points.end() );
    n= points.size();

    if(n<3)
    {
        for(int i=0; i<n; i++)
            ans[i]=points[i];
        Size= n;
        return ans;
    }

    ans[0]= base;
    for(int i=1; i<3; i++)
        ans[i]=points[i-1];

    int j=3;
    for( int i=2; i<n-1; i++ )
    {
        while( area( ans[j-2], ans[j-1], points[i] )!=2 )
            j--;
        ans[j++]= points[i];
        //cout<<j<<endl;
    }

    Size= j;

    return ans;

}

int main()
{
    int m,c;

    while(1)
    {
        scanf("%d %d", &m, &c);

        if( !(m+c) )
            break;

        point one,two;

        points.clear();

        for(int i=0; i<m; i++)
        {
            point p;
            scanf("%lld %lld", &p.x, &p.y);
            points.push_back(p);
        }

        sort( points.begin(), points.end(), cmp );

        for( int i=0;i<m;i++ )
            cout<<points[i].x<<" "<<points[i].y<<endl;

        vector<point> hull1= Hull(m);
        int sz1= Size;

        points.clear();

        for(int i=0; i<c; i++)
        {
            point p;
            scanf("%lld %lld", &p.x, &p.y);
            points.push_back(p);
        }

        vector<point> hull2= Hull(c);
        int sz2= Size;

        if(m<1 or c<1)
        {
            printf("Yes\n");
            continue;
        }

        if(m==1 and c==1)
        {
            if( hull1[0].x==hull2[0].x and hull1[0].y==hull2[0].y )
                printf("No\n");
            else
                printf("Yes\n");
            continue;
        }

        else if( (m==1 and c==2) or (m==2 and c==1) )
        {
            ll x,y,x1,y1,x2,y2;

            if(m==2)
            {
                x1= min( hull1[0].x, hull1[1].x );
                x2= max( hull1[0].x, hull1[1].x );
                y1= min( hull1[0].y, hull1[1].y );
                y2= max( hull1[0].y, hull1[1].y );
                x= hull2[0].x;
                y= hull2[0].y;
            }

            else
            {
                x1= min( hull2[0].x, hull2[1].x );
                x2= max( hull2[0].x, hull2[1].x );
                y1= min( hull2[0].y, hull2[1].y );
                y2= max( hull2[0].y, hull2[1].y );
                x= hull1[0].x;
                y= hull1[0].y;
            }

            if( x<=x2 and x>=x1 and y<=y2 and y>=y1 )
                printf("No\n");
            else
                printf("Yes\n");
            continue;
        }

        bool intersect= 0;

        hull1[sz1]=hull1[0];
        hull2[sz2]=hull2[0];
        //cout<<hull2.size()<<endl;;
        //cout<<hull2[0].x<<" "<<hull2[0].y<<" "<<hull2[1].x<<" "<<hull2[1].y<<endl;
        for(int i=0; i<sz1 and !intersect; i++)
            for(int j=0; j<sz2 and !intersect; j++)
            {
                int pos1= area( hull1[i],hull1[i+1], hull2[j] );
                int pos2= area( hull1[i],hull1[i+1], hull2[j+1] );
                int pos3= area( hull2[j],hull2[j+1], hull1[i] );
                int pos4= area( hull2[j],hull2[j+1], hull1[i+1] );
//                cout<<hull1[i].x<<" "<<hull1[i].x<<" "<<hull1[i+1].x<<" "<<hull1[i+1].y<<endl;
//                cout<<hull2[j].x<<" "<<hull2[j].x<<" "<<hull2[j+1].x<<" "<<hull2[j+1].y<<endl;
                if( pos1!=pos2 and pos3!=pos4 )
                    intersect= 1;
            }

        if(intersect)
            printf("No\n");
        else
        {
            //cout<<"aise\n";
            bool inside= 0;
            for(int i=0; sz1>2 and i<sz2 and !inside; i++)
            {
                int low=1, high= sz1-1, mid;

                while(high-low>1)
                {
                    mid= (low+high)>>1;
                    if( area( hull1[0], hull1[mid], hull2[i] )==2 )
                        low= mid;
                    else
                        high= mid;
                }

                int pos1= area( hull1[0], hull1[low], hull2[i] );
                int pos2= area( hull1[low], hull1[high], hull2[i] );
                int pos3= area( hull1[high], hull1[0], hull2[i] );

                if(pos1!=1 and pos2!=1 and pos3!=1)
                {
                   // cout<<"eikhane\n";
                    inside= 1;
                    break;
                }
            }

            if(inside)
                printf("No\n");
            else
            {
                for(int i=0; sz2>2 and i<sz1 and !inside; i++)
                {
                    int low=1, high= sz2-1, mid;

                    while(high-low>1)
                    {
                        mid= (low+high)>>1;
                        if( area( hull2[0], hull2[mid], hull1[i] )==2 )
                            low= mid;
                        else
                            high= mid;
                    }

                    int pos1= area( hull2[0], hull2[low], hull1[i] );
                    int pos2= area( hull2[low], hull2[high], hull1[i] );
                    int pos3= area( hull2[high], hull2[0], hull1[i] );

                    if(pos1!=1 and pos2!=1 and pos3!=1)
                    {
                        inside= 1;
                        break;
                    }
                }

                if(inside)
                    printf("No\n");
                else
                    printf("Yes\n");
            }
        }

    }

}

/*
    0 3
    3 0
    3 3
    2 3
    0 1
    0 2
    0 0
    */
