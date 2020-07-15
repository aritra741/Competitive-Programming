#include<bits/stdc++.h>
#define ll long long
#define sc second
#define mod 1000000007
#define mx 8007
#define inf 2e9
using namespace std;

class Automata
{
public:
    struct data
    {
        int link , len, cnt;
        int next[29] ;

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
ll ans= 0;

bool vis[mx*4];
int koyta[mx*4][2];
int k;

void dfs( int x )
{
    if( vis[x] )
        return;

    vis[x]= 1;

    koyta[x][0]= koyta[x][1]= 0;

    for( int i=0; i<28; i++ )
    {
        if( sa.node[x].next[i] )
        {
//            cout<<x<<" theke "<<i<<" hoye "<<sa.node[x].next[i]<<endl;
            if( i==26 )
                koyta[x][0]++;
            else if( i==27 )
                koyta[x][1]++;

            else
            {
                dfs( sa.node[x].next[i] );

                koyta[x][0]+= koyta[ sa.node[x].next[i] ][0];
                koyta[x][1]+= koyta[ sa.node[x].next[i] ][1];
            }
        }
    }

    if( x and koyta[x][0] and koyta[x][1]==k )
        ans+= (sa.node[x].len-sa.node[ sa.node[x].link ].len);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    string s,t;

    for( int tt=1; tt<=tc; tt++ )
    {
        cin>>s;
        cin>>t;
        cin>>k;

        s.push_back( (char)('z'+1) );
        s+= t;
        s.push_back( (char)('z'+2) );

        sa= Automata( s.size() );

        for( int i=0; i<s.size(); i++ )
            sa.addLetter( s[i] );

        dfs(0);

        cout<<"Case #"<<tt<<":\n";
        cout<<ans<<"\n";

        ans= 0;

        for( int i=0; i<sa.num; i++ )
            vis[i]= 0, koyta[i][0]= 0, koyta[i][1]= 0;
    }

}


