#include <bits/stdc++.h>
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define inf INT_MAX
using namespace std;

char grid[2010][2010];
int leftplusright[2010][2010];
int Left[2010][2010], Right[2010][2010];
bool vis[2010][2010];
int n,m,R,C;
int cnt= 0;
int limR, limL;
int d1[]= {-1,0,1,0};
int d2[]= {0,1,0,-1};

bool valid( int r, int c )
{
    if(r>=n or r<0)
        return 0;
    if(c>=m or c<0)
        return 0;
    if(grid[r][c]=='*')
        return 0;
    return 1;
}

bool operator < ( piiii a, piiii b )
{
    return a.second.first+a.second.second < b.second.first+b.second.second;
}

bool operator == ( piiii a, piiii b )
{
    return a.second.first+a.second.second == b.second.first+b.second.second;
}

void dijkstra()
{
    priority_queue<piiii> pq;
    pq.push( piiii( pii(R-1, C-1), pii( 0,0 ) ) );
    leftplusright[R-1][C-1]= 0;

    while(!pq.empty())
    {
        int left= pq.top().second.first;
        int right= pq.top().second.second;
        int r= pq.top().first.first;
        int c= pq.top().first.second;
        pq.pop();

        if(left>limL or right>limR)
            continue;

        if( left+right>leftplusright[r][c] )
            continue;

        if(!vis[r][c])
            vis[r][c]= 1, cnt++;

        for(int i=0; i<4; i++)
        {
            int uc= c+d2[i];
            int ur= r+d1[i];

            if(!valid( ur,uc ))
                continue;

            int uL= left;
            int uR= right;

            if( i==3 )
                {
                    uL++;
                    if(uL>limL)
                        continue;
                }
            if( i==1 )
                {
                    uR++;
                    if(uR>limR)
                        continue;
                }

            if( uL+uR<leftplusright[ur][uc] )
            {
                leftplusright[ur][uc]= uL+uR;
                pq.push( piiii( pii( ur,uc ), pii( uL,uR ) ) );
            }
        }
    }

}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d", &R, &C);
    scanf("%d %d", &limL, &limR);

    for(int i=0; i<n; i++)
        {
            scanf("%s", grid[i]);
            for(int j=0;j<m;j++)
                leftplusright[i][j]= inf;
        }


    dijkstra();

    printf("%d\n", cnt);
}
