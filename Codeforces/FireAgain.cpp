#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int n, m, mx= -1;
pii ans;
queue<pii> q;
int dist[2010][2010];
int dir1[]= {1,0,-1,0};
int dir2[]= {0,1,0,-1};

bool safe( pii p )
{
    if( p.x<=0 or p.y<=0 )
        return 0;
    if( p.x>n or p.y>m )
        return 0;
    return !dist[ p.x ][ p.y ];
}

void bfs()
{
    while(!q.empty())
    {
        pii u= q.front();
        q.pop();

        int d1= dist[u.x][u.y];

        for(int i=0;i<4;i++)
        {

            pii v= pii( u.x+dir1[i], u.y+dir2[i] );

            if( !safe( v ) )
                continue;

            dist[v.x][v.y]= d1+1;
            int d= dist[v.x][v.y];
            q.push( v );

            if( d>mx )
            {
                mx= d;
                ans.x= v.x, ans.y= v.y;
            }
        }
    }
}

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    cin>>n>>m;

    int k;
    cin>>k;

    while(k--)
    {
        pii l;
        cin>>l.x>>l.y;

        q.push( l );
        dist[l.x][l.y]= 1;
    }

    ans.x= 1, ans.y= 1;
    bfs();

    cout<< ans.x <<" "<< ans.y <<endl;
}
