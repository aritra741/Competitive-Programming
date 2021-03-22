#include <bits/stdc++.h>
#define ll long long
#define X 10050
#define Y 10050
using namespace std;

struct point
{
    ll x,y;
};

int area( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[i]-y[j]);
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

bool intersect( point p, point q, point r, point s )
{
    int pos1= area( p,q,r );
    int pos2= area( p,q,s );
    int pos3= area( r,s,p );
    int pos4= area( r,s,q );
 
    if(pos1!=pos2 and pos3!=pos4 and pos1 and pos2 and pos3 and pos4)
        return 1;
    return 0;
}

bool operator == (point a, point b)
{
    return a.x==b.x and a.y==b.y;
}

int n;
std::vector<int> adj[107];
int col[107];

int bfs(int x)
{
    queue<int>q;
    q.push(x);
    col[x]= 1;

    int one= 1, two= 0;
    int tot= 0;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        tot++;

        for( auto v: adj[u] )
        {
            if(!col[v])
            {
                if(col[u]==1)
                    col[v]= 2, two++;
                else
                    col[v]= 1, one++;
            }
        }
    }

    return max(one,two);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &n);

        int sz[n+5];
        point arr[n+5][107];

        for( int i=0;i<n;i++ )
        {
            col[i]= 0;
            adj[i].clear();
            int m;
            scanf("%d", &m);

            sz[i]= m;

            for( int j=0;j<m;j++ )
                scanf("%lld %lld", &arr[i][j].x, &arr[i][j].y);

            arr[i][m]= arr[i][0];
        }

        int ans= 0;

        for( int i=0;i<n;i++ )
        {
            int cnt= 0;
            for( int j=i+1;j<n;j++ )
            {
                bool f= 1;
                set<int>st;

                for( int k=0;k<sz[i] and f;k++ )
                {
                    for( int l=0;l<sz[j];l++ )
                    {
                        if( intersect( arr[i][k], arr[i][k+1], arr[j][l], arr[j][l+1] ) )
                        {
                            f= 0;
                            break;
                        }
                        int xx= area( arr[i][k], arr[i][k+1], arr[j][l] );
                        st.insert( xx );
                    }
                }

                if( !f or st.size()==1 )
                    adj[i].push_back(j), adj[j].push_back(i);
            }
        }

        for( int i=0;i<n;i++ )
        {
            // cout<<i<<" "<<adj[i].size()<<endl;
            if(!col[i])
                ans+= bfs(i);
        }

        printf("%d\n", ans);
    }
}
