#include <bits/stdc++.h>
#define pis pair<int, string>
using namespace std;

int n, lim, cnt;
int valid[10];
int vis[1000007];
bool inval[15];

bool init( int n )
{
    for(int i=0; i<n; i++)
        vis[i]= 0;
    lim= 0;
    for(int i=0;i<10;i++)
        inval[i]= 0;
}

string bfs()
{
    queue<pis> q;

    for(int i=0; i<lim; i++)
    {
        if(!valid[i])
            continue;
        char c= (char)valid[i]+'0';
        string s;
        s+= c;

        q.push( pis( valid[i]%n, s ) );

    }

    while( !q.empty() )
    {
        string s= q.front().second;
        int mod= q.front().first;
        q.pop();

        if( !mod )
            return s;
        if(vis[mod])
            continue;

        vis[mod]= 1;

        for( int i=0; i<lim; i++ )
        {
            string t= s;

            int tmp= (mod*10+valid[i])%n;

            t+= (char)valid[i]+'0';

            if(!vis[tmp])
                q.push( pis( tmp, t ) );
        }
    }

    return "-1";
}

int main()
{
    int tc= 1;

    while(scanf("%d %d", &n, &cnt)==2)
    {
        init(n);

        for(int i=0; i<cnt; i++)
        {
            int p;
            scanf("%d", &p);

            inval[p]= 1;
        }

        for(int i=0; i<10; i++)
            if( !inval[i] )
                valid[lim++]= i;

        printf("Case %d: ", tc++);

        cout<< bfs() <<endl;
    }
}
