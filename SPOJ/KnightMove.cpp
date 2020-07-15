#include <bits/stdc++.h>
#define pii pair<int,int>
#define inf 1e9
using namespace std;

int dist[1010][1010];
int d1[]= {1,1,2,2,-1,-1,-2,-2};
int d2[]= {2,-2,1,-1,2,-2,1,-1};

bool valid( int x, int y )
{
    if(x<0 or y<0)
        return 0;
    if(x>=1000 or y>=1000)
        return 0;
    if(dist[x][y]!=inf)
        return 0;
    return 1;
}

void bfs()
{
    fill(dist[0], dist[1000], inf);

    queue<pii> q;
    q.push( pii(0,0) );
    dist[0][0]= 0;

    while(!q.empty())
    {
        int X= q.front().first;
        int Y= q.front().second;
        q.pop();

        for(int i=0; i<8; i++)
        {
            int x1= X+d1[i];
            int y1= Y+d2[i];

            if(!valid(x1,y1))
                continue;

            dist[x1][y1]= dist[X][Y]+1;
            q.push(pii(x1,y1) );
        }
    }
}

int main()
{
    bfs();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        x--, y--;

        printf("%d\n", dist[x][y]);

    }
}
