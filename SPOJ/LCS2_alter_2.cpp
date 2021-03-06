#include<bits/stdc++.h>
#define ll long long
#define sc second
#define mod 1000000007
#define mx 200010*10
#define inf 2e9
using namespace std;

bitset<10>bs[mx];
char s[mx];

class Automata
{
public:
    struct data
    {
        int link , len, cnt;
        int next[37] ;

        data() {}
        data(int link,int len) : link(link) , len(len) {}
    };

    data *node ;
    int num , last ;
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

    void count_sub_str(){
        for( auto it = st.rbegin(); it != st.rend(); it++ ){
            node[ node[it->sc].link ].cnt += node[it->sc].cnt;
        }
    }
};

Automata sa;
int ans;
int num;
bool vis[mx];

void dfs( int p )
{
    if(vis[p])
        return;
    vis[p]= 1;

    for( int i=0;i<37;i++ )
    {
        if( sa.node[p].next[i] )
        {
            if( i>25 )
            {
                bs[p][i-26]= 1;
            }
            else
            {
                dfs( sa.node[p].next[i] );
                bs[p]|= bs[ sa.node[p].next[i] ];
            }
        }
    }

    if( bs[p].count()==num )
        ans= max( ans, sa.node[p].len );
}

int main()
{
    char t[mx/10];
    int n;

    while( scanf("%s", t)!=EOF )
    {
        n= strlen(s);
        num++;
        int sz= strlen(t);

        for( int i=0;i<sz;i++ )
            s[n+i]= t[i];
        s[n+sz]= 'z'+num;
    }

    n= strlen(s);
    sa= Automata( n );

    for(int i=0;i<n;i++)
        sa.addLetter(s[i]);

    dfs(0);

    printf("%d\n", ans);
}

/*
aab
baa
*/
