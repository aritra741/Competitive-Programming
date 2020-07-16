#include<bits/stdc++.h>
#define mod1 1000001699
#define mod2 1000003469
#define sc second
#define p1 43
#define p2 37
#define ll long long
#define mx 100007
using namespace std;

ll pp1[mx], pp2[mx];
ll pre1[mx], post1[mx];
ll pre2[mx], post2[mx];

void init()
{
    ll x= p1, y= p2;
    pp1[0]= 1, pp2[0]= 1;

    for( int i=1;i<mx;i++ )
    {
        pp1[i]= ( pp1[i-1]*x )%mod1;
        pp2[i]= ( pp2[i-1]*y )%mod2;
    }
}

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
        int let = ch - 'A' ;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    string s;
    cin>>s;

    sa= Automata(s.size());

    for( int i=0;i<s.size();i++ )
    {
        sa.addLetter(s[i]);

        if(i)
            pre1[i]= ( pre1[i-1]+(( s[i]-'A' )+1)*pp1[i+1] )%mod1,
            pre2[i]= ( pre2[i-1]+(( s[i]-'A' )+1)*pp2[i+1] )%mod2;
        else
            pre1[i]= ((( s[i]-'A' )+1)*pp1[i+1] )%mod1,
            pre2[i]= ((( s[i]-'A' )+1)*pp2[i+1] )%mod2;
    }

    for( int i=s.size()-1;i>=0;i-- )
    {
        if(i<s.size()-1)
            post1[i]= ((s[i]-'A'+1)*p1+post1[i+1]*p1)%mod1,
            post2[i]= ((s[i]-'A'+1)*p2+post2[i+1]*p2)%mod2;
        else
            post1[i]= (s[i]-'A'+1)*p1,
            post2[i]= (s[i]-'A'+1)*p2;
    }

    sa.count_sub_str();

    int x= 0;
    vector<int>v,vv;

    for( int i=0;i<s.size();i++ )
    {
        x= sa.node[x].next[ s[i]-'A' ];

        int oidike= s.size()-1-i;

        if( pre1[i]==post1[oidike] and pre2[i]==post2[oidike] )
            v.push_back(i+1),vv.push_back(sa.node[x].cnt);
    }

    cout<<v.size()<<'\n';

    for( int i=0;i<v.size();i++ )
    {
        cout<<v[i]<<" "<<vv[i]<<'\n';
    }
}
