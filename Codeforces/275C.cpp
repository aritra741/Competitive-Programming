#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct Hp{const int oo=1e9;int n;
    vector<int> mL,mR,d;vector<vector<int>>g;
    Hp(int n):n(n),mL(n+1),mR(n+1),d(n+1),g(n+1){}
    void edge(int u,int v){g[u].pb(v);/*both part diff 1..n*/}
    bool B(){queue<int> q;
    for(int u=1;u<=n;u++)if(mL[u])d[u]=oo;else d[u]=0,q.push(u);
    d[0]=oo;while(!q.empty()){int u=q.front();q.pop();
    for(auto v:g[u]){if(d[mR[v]]==oo)d[mR[v]]=d[u]+1,q.push(mR[v]);}}
    return d[0]!=oo;}
    bool D(int u){if(!u)return 1;for(auto v:g[u])if(d[mR[v]]==d[u]+1&&D(mR[v]))
    {mL[u]=v;mR[v]=u;return 1;}d[u]=oo;return false;}
    int A(){int r=0;while(B())for(int u=1;u<=n;u++)if(!mL[u]&&D(u))r++;return r;}};


int arr[100007];
map<int,int>ase;

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    Hp bpm(n);

    for( int i=1; i<=n; i++ )
        scanf("%d", &arr[i]), ase[ arr[i] ]= i;

    for( int i=1; i<=n; i++ )
        if( (ll)k*arr[i]<=1000000000 and ase[ k*arr[i] ] and ase[ k*arr[i] ]!=i )
            bpm.edge( i, ase[k*arr[i]] ),
            bpm.edge( ase[k*arr[i]], i );

    int matched= bpm.A();

    printf("%d\n", n-matched/2);
}


