#include <bits/stdc++.h>
#define ll long long
#define inf 2e9
using namespace std;

const int maxn=100010;
char s[maxn];


/// 1-based
namespace Automata {
	int root,sz,last,n;
	int par[maxn<<1],len[maxn<<1],ch[maxn<<1][26],mat[maxn<<1],f[maxn<<1];
	int b[maxn],id[maxn<<1];
	void Extend(int c) {
		int np=++sz,p=last;last=np;
		len[np]=len[p]+1;
		for (;p && !ch[p][c];p=par[p]) ch[p][c]=np;
		if (!p) par[np]=root;
		else {
			int q=ch[p][c];
			if (len[q]==len[p]+1) par[np]=q;
			else {
				int nq=++sz;len[nq]=len[p]+1;
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				par[nq]=par[q];
				par[np]=par[q]=nq;
				for (;p && ch[p][c]==q;p=par[p]) ch[p][c]=nq;
			}
		}
	}
	void build() {
		last=sz=root=1;
		n=strlen(s+1);
		for (int i=1;i<=n;i++) Extend(s[i]-'a');
	}
	void pre() {
		for (int i=1;i<=sz;i++) b[len[i]]++;
		for (int i=1;i<=n;i++) b[i]+=b[i-1];
		for (int i=1;i<=sz;i++) id[b[len[i]]--]=i;
		for (int i=1;i<=sz;i++) mat[i]=inf;
	}
	void match() {
		int n=strlen(s+1);
		int cnt=0;

        int p= root, ekhon_match= 0;

        for( int i=1;i<=sz;i++ )
            f[i]= 0;            /// ith node e maximum koto match paisi

        for( int i=1;i<=n;i++ )
        {
            int c= s[i]-'a';
            while( p>1 and !ch[p][c] )
                p= par[p], ekhon_match= len[p];
            if( ch[p][c] )
            {
                p= ch[p][c];
                f[p]= max( f[p], ++ekhon_match );
            }
        }

        for( int i=sz;i>=1;i-- )
        {
            if( f[ id[i] ] )
                f[ par[id[i]] ]= len[ par[id[i]] ];     /// id[i] e match thakle or link eo match thakbe
        }

        for( int i=1;i<=sz;i++ )
            mat[i]= min( mat[i], f[i] );        /// ith node e shob match er minimum ta nile intersection pabo
	}
}

using namespace Automata;

int main() {

	scanf("%s", s+1);
	build();
	pre(); /// for O(n) topo sort

	while( scanf("%s", s+1)!=EOF )
        match();

    int ans= 0;

    for( int i=1;i<=sz;i++ )
        ans= max( ans, mat[i] );

    printf("%d\n", ans);
}
