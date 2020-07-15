#include <bits/stdc++.h>
#define pii pair<int,int>
#define inf 1e9
using namespace std;

int dist[510][510];
char Move[510][510];
int d1[]= {1,0,-1,0};
int d2[]= {0,-1,0,1};
int n,m;

bool valid( int x, int y )
{
    if(x<0 or y<0)
        return 0;
    if(x>=n or y>=m)
        return 0;
    if(dist[x][y]!=inf)
        return 0;
    return 1;
}

void bfs()
{
    queue<pii> q;
    q.push( pii(0,0) );
    dist[0][0]= 0;

    while(!q.empty())
    {
        int X= q.front().first;
        int Y= q.front().second;
        q.pop();

        if( X==n-1 and Y==m-1 )
            break;

        for(int i=0;i<4;i++)
        {
            int x1= X+ d1[i]*(Move[X][Y]-'0');
            int y1= Y+ d2[i]*(Move[X][Y]-'0');

            if( !valid(x1,y1) )
                continue;

            dist[x1][y1]= dist[X][Y]+1;
            q.push( pii(x1,y1) );
        }
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>> Move[i][j];

    fill( dist[0], dist[n+1], inf );

    bfs();

    if( dist[n-1][m-1]==inf )
        cout<<"-1\n";
    else
        cout<< dist[n-1][m-1] <<endl;
}
