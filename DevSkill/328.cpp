#include<bits/stdc++.h>
#define ll long long
#define sc second
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

Automata sa;
int mil[30007];
int dp[30007];
int vis[30007];

int pp;
int n,x,y,k;

int rec( int i )
{
    if( i>=n )
        return 0;
    if( vis[i]==pp )
        return dp[i];

    int ret= 2e9;

    for( int j=i+2;j<=i+mil[i];j++ )
        ret= min( ret, y+rec( j ) );

    ret= min( ret, x+rec( i+1 ) );

//    cout<<i<<" "<<ret<<endl;

    vis[i]= pp;

    return dp[i]= ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        pp++;
        char s[30007];

        scanf("%d %d %d %d", &n, &x, &y, &k);
        scanf("%s", s);

        int sz= strlen(s);

        sa= Automata( sz );

        sa.addLetter(s[0]);

        int sum= x;

        for( int i=1; i<sz; i++ )
        {
//            cout<<i<<endl;
            int p= 0, m= mil[i], xx= i;
            for( int j=i+mil[i]; j<sz; j++ )
            {
                int c= s[j]-'a';

                if( sa.node[p].next[c] )
                {
//                    cout<<c<<" "<<p<<" "<<sa.node[p].next[c]<<endl;
                    p= sa.node[p].next[c];
                    xx= j;
                }
                else
                    break;
            }

            m= max(m,xx-i+1);
            mil[i]= m;

            for( int j=i; j<=xx; j++ )
               mil[j]= max( mil[j], min( m-(j-i), k ) ), sa.addLetter( s[j] );
        }

        for( int i=0;i<sz;i++ )
            cout<<i<<" "<<mil[i]<<endl;

        printf("%d\n", x+rec(1));
    }
}


