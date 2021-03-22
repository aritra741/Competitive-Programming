#include<bits/stdc++.h>
#define ll long long
#define sc second
#define mod 1000000007
#define mx 200010
#define inf 2e9
using namespace std;

char s[mx];

class Automata
{
public:
    struct data
    {
        int link, len, cnt, dist;
        int next[27] ;

        data() {}
        data(int link, int len) : link(link), len(len) {}
    };

    data *node ;
    int mat[mx], hit_node[mx];
    bool visfordfs[mx];
    int num, last ;
    set< pair<int, int> > st;

    void reset()
    {
        num = 1 ;

        node[0].link = -1 ;
        node[0].len = 0 ;
        node[0].cnt = 0 ;
        last = 0 ;
        memset(node[0].next, 0, sizeof(node[0].next));
    }

    Automata() {}
    Automata(int mx_len)
    {
        mx_len += 7 ;
        mx_len = mx_len * 2 ;
        node = new data[mx_len] ;

        memset( mat, 0x3f, sizeof(mat) );
        // memset( visfordfs, 0, sizeof(visfordfs) );

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
        memset(node[cur].next, 0, sizeof(node[cur].next));

        for (p = last ; p != -1 && !node[p].next[let] ; p = node[p].link)
            node[p].next[let] = cur ;

        if (p == -1)
            node[cur].link = 0 ;

        else
        {
            int q = node[p].next[let] ;

            if (node[p].len + 1 == node[q].len)
                node[cur].link = q ;

            else
            {
                int clone = num++;
                node[clone] = node[q] ;
                node[clone].len = node[p].len + 1 ;
                node[clone].cnt = 0;
                st.insert({node[clone].len, clone});

                for (; p != -1 && node[p].next[let] == q ; p = node[p].link)
                    node[p].next[let] = clone ;

                node[q].link = node[cur].link = clone ;
            }
        }
        last = cur ;
    }

    void count_sub_str()
    {
        for ( auto it = st.rbegin(); it != st.rend(); it++ )
        {
            node[ node[it->sc].link ].cnt += node[it->sc].cnt;
        }
    }

    void count_dist_str( int x )
    {
        if ( node[x].dist )
            return;

        node[x].dist = 1;

        for ( int i = 0; i < 26; i++ )
            if ( node[x].next[i] )
            {
                count_dist_str( node[x].next[i] );
                node[x].dist += node[ node[x].next[i] ].dist ;
            }
    }

    // void kth( int x )
    // {
    //     for ( int i = 0; i < 26; i++ )
    //     {
    //         if (k <= 0)
    //             break;
    //         if ( sa.node[x].next[i] )
    //         {
    //             k -= sa.node[sa.node[x].next[i]].cnt;
    //             kth( sa.node[x].next[i] );

    //             if (k <= 0)
    //                 ans.push_back( i + 'a' );
    //         }
    //     }
    // }

    ll dfs( int x )
    {
        visfordfs[x]= 1;
        ll tot= 0;
        ll ret= 0;

        if( node[x].link!=-1 )
        {
            tot= node[x].len-node[node[x].link].len;
            ll occ= node[x].cnt;
            ll ways= (occ*(occ+1))/2;
            ways*= tot;
            ret+= ways;
        }

        for ( int i = 0; i < 26; i++ )
        {
            if ( node[x].next[i]>0 and !visfordfs[node[x].next[i]] )
            {
                ret+= dfs( node[x].next[i] );
            }
        }

        return ret;
    }
};

Automata sa;

int main()
{
    scanf("%s", s);
    int sz = strlen(s);

    sa = Automata( sz );

    for ( int i = 0; i < sz; i++ )
        sa.addLetter( s[i] );

    ll ans = 0;

    sa.count_sub_str();

     printf("%lld\n", sa.dfs(0));
}
