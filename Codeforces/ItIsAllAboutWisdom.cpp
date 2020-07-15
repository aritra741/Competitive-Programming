#include <bits/stdc++.h>
#define mx 100007
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pii>
using namespace std;

vector<piii> adj[mx];
vector<int> wis;
bool vis[mx];
ll dist[mx];

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        memset( dist, 0x3f, sizeof(dist) );

        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);

        for(int i=0;i<m;i++)
        {
            int p,q,w,c;
            scanf("%d %d %d %d", &p, &q, &w, &c);
            adj[p].push_back( piii( q, pii(c,w) ) );
            adj[q].push_back( piii( p, pii(c,w) ) );
            wis.push_back( w );
        }
    }

    sort(wis.begin(), wis.end());

    int sz= wis.size();
    int low= wis[0];
    int high= wis[sz-1];
    int mid= (low+high)/2;

    while(low<=high)
    {
        mid= (low+high)/2;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[1]= 0;
        pq.push(1);

        while(!pq.empty())
        {
            if(  )
        }
    }


}
