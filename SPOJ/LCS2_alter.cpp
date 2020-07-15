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
        data(int link,int len) : link(link), len(len) {}
    };

    data *node ;
    int mat[mx], hit_node[mx];
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

        memset( mat, 0x3f, sizeof(mat) );

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

    void match()
    {
        int p= 0;
        int n= strlen(s);

        int ekhon_match= 0;

        for( int i=0;i<num;i++ )
            hit_node[i]= 0;

        for( int i=0;i<n;i++ )
        {
            int c= s[i]-'a';
            while( p and !node[p].next[c] )
                p= node[p].link, ekhon_match= node[p].len;

            if( node[p].next[c] )
            {
                p= node[p].next[c];
                hit_node[p]= max( hit_node[p], ++ekhon_match );
            }
        }

        for( auto it = st.rbegin(); it != st.rend(); it++ )
        {
            if( hit_node[it->sc] )
                hit_node[ node[it->sc].link ]= node[node[it->sc].link].len;
        }

        for( int i=0;i<num;i++ )
            mat[i]= min( mat[i], hit_node[i] );
    }
};

Automata sa;

int main()
{
    scanf("%s", s);
    int sz= strlen(s);

    sa= Automata( sz );

    for( int i=0;i<sz;i++ )
        sa.addLetter( s[i] );

    while( scanf("%s", s)!=EOF )
        sa.match();

    int ans= 0;
    for( int i=0;i<sa.num;i++ )
        ans= max( ans, sa.mat[i] );

    printf("%d\n", ans);
}

