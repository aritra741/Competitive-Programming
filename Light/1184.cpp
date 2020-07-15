#include<bits/stdc++.h>
#define mx 55
using namespace std;

struct person
{
    int age, height, dv;
};

vector<person> aa, bb;
vector<int> adj[mx];
bool vis[mx];
int mr[mx], ml[mx];

int dfs( int y )
{
    vis[y]= 1;
    for( int i=0; i<adj[y].size(); i++ )
    {
        int z= adj[y][i];

        if( mr[z]==-1 or (!vis[ mr[z] ]  and dfs( mr[z] ) ) )
        {
            ml[y]= z;
            mr[z]= y;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1; t<=tc; t++ )
    {
        memset( mr, -1, sizeof(mr) );
        memset( ml, -1, sizeof(ml) );

        int n,m;
        scanf("%d %d", &n, &m);

        for( int i=0;i<n;i++ )
        {
            person p;
            scanf("%d %d %d", &p.height, &p.age, &p.dv);

            aa.push_back(p);
        }

        for( int i=0;i<m;i++ )
        {
            person p;
            scanf("%d %d %d", &p.height, &p.age, &p.dv);

            bb.push_back(p);
        }

        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ )
                if( abs(bb[j].height-aa[i].height)<=12 )
                    if( abs( aa[i].age-bb[j].age )<=5 )
                        if( aa[i].dv==bb[j].dv )
                            adj[i].push_back(j);

        int ans= 0;
        for( int i=0; i<n; i++ )
        {
            memset( vis,0,sizeof(vis) );

            ans+= dfs( i );
        }

        cout<<"Case "<<t<<": "<<ans<<endl;

        for( int i=0;i<n;i++ )
            adj[i].clear();

        aa.clear();
        bb.clear();
    }
}

