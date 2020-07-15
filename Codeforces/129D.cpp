#include<bits/stdc++.h>
#define ll long long
#define sc second
using namespace std;

class Automata
{
public:
    struct data
    {
        int link , len, cnt;
        int next[27] ;

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
string ans;

int k;

void kth( int x )
{
    for( int i=0;i<26;i++ )
    {
        if(k<=0)
            break;
        if( sa.node[x].next[i] )
        {
            k-= sa.node[sa.node[x].next[i]].cnt;
            kth( sa.node[x].next[i] );

            if(k<=0)
                ans.push_back( i+'a' );
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    cin>>k;

    sa= Automata( s.size() );

    for( int i=0;i<s.size();i++ )
        sa.addLetter( s[i] );

    ll sz= s.size();

    if( (sz*(sz+1)/2<k ) )
      return cout<<"No such line.\n", 0;

    kth(0);

    reverse( ans.begin(), ans.end() );

    cout<<ans<<'\n';
}
