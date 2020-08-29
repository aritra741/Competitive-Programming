#include<bits/stdc++.h>
#define ll long long
#define M 200007
using namespace std;

class Automata
{
public:
    struct data
    {
        int link, len, cnt, dist;
        int next[28] ;

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

//    void count_sub_str()
//    {
//        for( auto it = st.rbegin(); it != st.rend(); it++ )
//        {
//            node[ node[it->sc].link ].cnt += node[it->sc].cnt;
//        }
//    }

    void count_dist_str( int x )
    {
        if( node[x].dist )
            return;

        if(x)
            node[x].dist= 1;
        else
            node[x].dist= 0;

        for( int i=0; i<27; i++ )
            if( node[x].next[i] )
            {
                count_dist_str( node[x].next[i] );
                node[x].dist+= node[ node[x].next[i] ].dist ;
            }
    }
};

Automata sa;
char s[200007], tt[200007];
bool vis[400007];
ll baad;

void dfs( int x )
{
    if( vis[x] )
        return;
    vis[x]= 1;

    for( int i=0;i<28;i++ )
    {
        if( sa.node[x].next[i] )
        {
            dfs( sa.node[x].next[i] );
            baad+= sa.node[ sa.node[x].next[i] ].len-sa.node[sa.node[ sa.node[x].next[i] ].link].len;
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++)
    {
        scanf("%s", s);
        scanf("%s", tt);

        int n= strlen(s);
        int m= strlen(tt);

        sa= Automata(n);

        for( int i=0;i<n;i++ )
            sa.addLetter( s[i] );
        sa.count_dist_str(0);

        ll tot= sa.node[0].dist;

        tt[m]= 'a'+1;
        tt[m+1]= 0;
        m++;

        for( int i=m;i<m+n;i++ )
            tt[i]= s[i-m];
        n+= m;
        s[n]= 0;

        sa= Automata(n);

        for( int i=0;i<n;i++ )
            sa.addLetter( s[i] );

        sa.count_dist_str(0);

        int p= 0;

        for( int i=0;i<m;i++ )
        {
            int c= tt[i]-'a';

            while( p and !sa.node[p].next[c] )
                p= sa.node[p].link;
        }

        dfs(p);

        printf("%lld\n", tot-baad);
    }
}


