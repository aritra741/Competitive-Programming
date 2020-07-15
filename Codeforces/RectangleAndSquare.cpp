#include <bits/stdc++.h>
using namespace std;

struct pt
{
    int x,y;
};

vector<pt> v;

int sign( pt p, pt q, pt r )
{
    int val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

int dot(pt a, pt b)
{
    return a.x * b.x + a.y * b.y;
}

int dist( pt a, pt b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool issquare( pt a, pt b, pt c, pt d )
{
    pt arr[4];
    arr[0]= a;
    arr[1]= b;
    arr[2]= c;
    arr[3]= d;

    for( int i=0; i<4; i++ )
        for( int j=0; j<4; j++ )
            for( int k=0; k<4; k++ )
                for( int l=0; l<4; l++ )
                    if( i!=j and i!=k and i!=l and j!=k and j!=l and k!=l )
                        if( dist( arr[i], arr[j] )==dist( arr[j], arr[k] ) )
                            if( dist(arr[j],arr[k])==dist( arr[k],arr[l] ) and dist( arr[k], arr[l] )==dist( arr[i],arr[l] ) )
                            {
                                pt p,q,r;
                                p.x= arr[i].x-arr[j].x;
                                p.y= arr[i].y-arr[j].y;
                                q.x= arr[k].x-arr[j].x;
                                q.y= arr[k].y-arr[j].y;
                                r.x= arr[l].x-arr[k].x;
                                r.y= arr[l].y-arr[k].y;

                                if( dot( p,q )==0 and dot( q,r )==0 )
                                    return 1;
                            }
    return 0;
}

bool isrect( pt a, pt b, pt c, pt d )
{
    pt arr[4];
    arr[0]= a;
    arr[1]= b;
    arr[2]= c;
    arr[3]= d;

    for( int i=0; i<4; i++ )
        for( int j=0; j<4; j++ )
            for( int k=0; k<4; k++ )
                for( int l=0; l<4; l++ )
                    if( i!=j and i!=k and i!=l and j!=k and j!=l and k!=l )
                        if( dist( arr[i], arr[j] )==dist( arr[l], arr[k] ) )
                            if( dist(arr[j],arr[k])==dist( arr[i],arr[l] ) )
                            {
                                pt p,q,r;
                                p.x= arr[i].x-arr[j].x;
                                p.y= arr[i].y-arr[j].y;
                                q.x= arr[k].x-arr[j].x;
                                q.y= arr[k].y-arr[j].y;
                                r.x= arr[l].x-arr[k].x;
                                r.y= arr[l].y-arr[k].y;

                                if( dot( p,q )==0 and dot( q,r )==0 )
                                    return 1;
                            }
    return 0;
}


int main()
{
    for( int i=0; i<8; i++ )
    {
        pt p;
        scanf("%d %d", &p.x, &p.y);

        v.push_back(p);
    }

    for( int i=0; i<8; i++ )
        for( int j=0; j<8; j++ )
            for( int k=0; k<8; k++ )
                for( int l=0; l<8; l++ )
                {
                    if( i==j or i==k or i==l or j==k or j==l or k==l )
                        continue;
                    if( !sign( v[i], v[j], v[k] ) )
                        continue;
                    if( !sign( v[i], v[j], v[l] ) )
                        continue;

                    if(!issquare( v[i], v[j], v[k], v[l] ))
                        continue;

                    for( int a=0; a<8; a++ )
                        for( int b=0; b<8; b++ )
                            for( int c=0; c<8; c++ )
                                for( int d=0; d<8; d++ )
                                {
                                    if( a==b or a==c or a==d or b==c or b==d or c==d )
                                        continue;
                                    if( a==i or a==j or a==k or a==l )
                                        continue;
                                    if( b==i or b==j or b==k or b==l )
                                        continue;
                                    if( c==i or c==j or c==k or c==l )
                                        continue;
                                    if( d==i or d==j or d==k or d==l )
                                        continue;
                                    if( !sign( v[a], v[b], v[c] ) )
                                        continue;
                                    if( !sign( v[a], v[b], v[d] ) )
                                        continue;

                                    if( isrect( v[a], v[b], v[c], v[d] ) )
                                    {
                                        cout<<"YES\n";

                                        cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<endl;
                                        cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
                                        return 0;
                                    }
                                }
                }

    cout<<"NO\n";
}
