#include<bits/stdc++.h>
#define ll long long
#define sc second
using namespace std;

class Automata
{
public:
    struct data
    {
        int link, len, cnt, dist, id;
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
        node[0].id = cur ;
        st.insert({node[cur].len, cur});
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
                st.insert({node[clone].len, clone});

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

Automata sa;
char s[1200007], p[1200007];
int k, sz1, sz2;
ll ans;

void dfs( int x, int cnt, int d )
{
    if( d>sz2 )
        return;
    for( int i=0; i<26; i++ )
    {
        if( sa.node[x].next[i] )
        {
            if( p[d-1]-'a'!=i )
            {
                if( cnt+1<=k and d==sz2 )
                    ans+= 1LL*sa.node[sa.node[x].next[i]].cnt;
                if( d<sz2 )
                    dfs( sa.node[x].next[i], cnt+1, d+1 );
            }
            else
            {
                if( cnt<=k and d==sz2 )
                    ans+= 1LL*sa.node[sa.node[x].next[i]].cnt;
                dfs( sa.node[x].next[i], cnt, d+1 );
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        scanf("%s %s %d", s, p, &k);

        sz1= strlen(s);
        sz2= strlen(p);

        sa= Automata( sz1 );

        for( int i=0; i<sz1; i++ )
            sa.addLetter( s[i] );

        sa.count_sub_str();
        sa.count_dist_str(0);

        dfs( 0, 0, 1 );

        printf("Case %d: %lld\n", t, ans);

        ans= 0;
    }
}


