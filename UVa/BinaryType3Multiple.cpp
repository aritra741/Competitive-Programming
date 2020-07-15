#include <bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<pii, bool>
#define f first
#define s second
#define inf 2e9
using namespace std;

int dist[1000007][2];
int n;

pii bfs()
{
    queue<piii> q;
    q.push( piii(pii(3%n,1),0) );
    dist[3%n][0]= 1;

    while( !q.empty() )
    {
        int mod= q.front().f.f;
        int three= q.front().f.s;
        bool taken= q.front().s;
        q.pop();

        if(!mod)
            return pii( dist[mod][taken], three );

        int tmp1= (mod*10+3)%n;

        if( !taken and dist[tmp1][0]==-1 )
        {
            dist[tmp1][0]= dist[mod][taken]+1;
            q.push( piii(pii( tmp1, three+1 ), taken) );
        }

        int tmp2= (mod*10)%n;

        if( dist[tmp2][1]==-1 )
        {
            dist[tmp2][1]= dist[mod][taken]+1;
            q.push( piii(pii( tmp2, three ), 1) );
        }
    }
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        for(int i=0; i<=n; i++)
            dist[i][0]= -1,
            dist[i][1]= -1;

        pii ans;
        ans= bfs();

        printf("%d %d %d\n", ans.f, ans.s, ans.f-ans.s);
    }
}
