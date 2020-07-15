#include<bits/stdc++.h>
#define ll long long
#define sc second
#define mod 1000000007
using namespace std;

class Automata
{
public:
    struct data
    {
        int link, len, cnt, dist;
        int next[27] ;

        data() {}
        data(int link,int len) : link(link), len(len) {}
    };

    data *node ;
    int num, last ;
    set< pair<int, int> > st;

    void reset()
    {
        num = 1 ;

        node[0].link = -1 ;
        node[0].len = 0 ;
        node[0].cnt = 0 ;
        last = 0 ;
        memset(node[0].next,0,sizeof(node[0].next));
    }

    Automata() {}
    Automata(int mx_len)
    {
        mx_len += 7 ;
        mx_len = mx_len*2 ;
        node = new data[mx_len] ;

        reset();
    }

    void addLetter(char ch)
    {
        int cur = num++;
        int let = ch - 'a' ;
        int p = last ;

        node[cur].len = node[last].len + 1 ;
        node[cur].cnt = 1;
//        st.insert({node[cur].len, cur});
        memset(node[cur].next,0,sizeof(node[cur].next));

        for(p=last ; p != -1 && !node[p].next[let] ; p = node[p].link)
            node[p].next[let] = cur ;

        if(p == -1)
            node[cur].link = 0 ;

        else
        {
            int q = node[p].next[let] ;

            if(node[p].len+1 == node[q].len)
                node[cur].link = q ;

            else
            {
                int clone = num++;
                node[clone] = node[q] ;
                node[clone].len = node[p].len + 1 ;
                node[clone].cnt = 0;
//                st.insert({node[clone].len, clone});

                for(; p != -1 && node[p].next[let] == q ; p = node[p].link)
                    node[p].next[let] = clone ;

                node[q].link = node[cur].link = clone ;
            }
        }
        last = cur ;
    }

    void count_sub_str()
    {
        for( auto it = st.rbegin(); it != st.rend(); it++ )
        {
            node[ node[it->sc].link ].cnt += node[it->sc].cnt;
        }
    }

    void count_dist_str( int x )
    {
        if( node[x].dist )
            return;

        node[x].dist= 1;

        for( int i=0; i<26; i++ )
            if( node[x].next[i] )
            {
                count_dist_str( node[x].next[i] );
                node[x].dist+= node[ node[x].next[i] ].dist ;
            }
    }
};

bool vis[2000007];
int arr[2000007], sum[2000007];
Automata sa;

void bfs()
{
    queue<int>q;
    vis[0]= 1;
    q.push(0);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        if( sa.node[u].link>-1 )
        {
            int l= sa.node[sa.node[u].link].len+1;
            int r= sa.node[u].len;

            arr[l]++;
            arr[r+1]--;
        }

        for( int i=0;i<26;i++ )
        {
            if( sa.node[u].next[i] and !vis[sa.node[u].next[i]] )
            {
                vis[ sa.node[u].next[i] ]= 1;
                q.push( sa.node[u].next[i] );
            }
        }
    }
}

ll Pow( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

int main()
{
    sum[0]= 1;
    ll x= 1;

    for( int i=1;i<2000007;i++ )
        x= (x*26)%mod, sum[i]= ( sum[i-1]+x )%mod;

    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        char s[1000007];
        scanf("%s", s);

        int sz= strlen(s);

        sa= Automata( sz );

        for( int i=0; i<sz; i++ )
            sa.addLetter( s[i] );

        bfs();

        for( int i=1;i<=sz;i++ )
            arr[i]= (arr[i-1]+arr[i])%mod;
        for( int i=1;i<=sz;i++ )
            arr[i]= (arr[i-1]+arr[i])%mod;

        printf("Case %d:\n", t);

        int q;
        scanf("%d", &q);

        while(q--)
        {
            int l,r;
            scanf("%d %d", &l, &r);

            ll ase= (arr[r]-arr[l-1]+mod)%mod;
            ll tot= ( sum[r]-sum[l-1]+mod )%mod;
            ll ans= ( tot-ase+mod )%mod;

            printf("%lld\n", ans);
        }

        for( int i=0;i<2000007;i++ )
            arr[i]= 0, vis[i]= 0;
    }
}

