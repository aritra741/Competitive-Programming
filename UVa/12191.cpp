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
        int link , len, cnt;
        int next[65] ;

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
        int let = ch - 'a'+38 ;
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

int main()
{
    while(1)
    {
        scanf("%s", s);

        if(s[0]=='*')
            break;

        int sz= strlen(s);

        sa= Automata( sz );

        for( int i=0; i<sz; i++ )
        {
            int c= s[i];
            if( c>='0' and c<='9' )
                c= (int)'a'-(c-'0')-1;
            else if( c>='A' and c<='Z' )
                c= (int)'a'-(c-'A')-11;
            else if( c=='.' )
                c= 'a'-37;
            else if( c==',' )
                c= 'a'-38;

            sa.addLetter( c );
        }
        ll ans= 0;

        sa.count_sub_str();

        for( auto it = sa.st.rbegin(); it != sa.st.rend(); it++ )
        {
            if( sa.node[it->sc].cnt>1 )
                ans+= (sa.node[it->sc].len-sa.node[ sa.node[it->sc].link ].len);
        }

        printf("%lld\n", ans);
    }
}



