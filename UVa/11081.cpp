#include <bits/stdc++.h>
#define mod 10007
using namespace std;

string a,b,c;
int p,q,r;
int dp[67][67][67];
int vis[67][67][67];
int pp;

int rec( int i, int j, int k )
{
	if( k==r )
		return 1;
	if( i>=p and j>=q )
		return 0;
	if( vis[i][j][k]==pp )
		return dp[i][j][k];

	int ret= 0;

	for( int x=i;x<p;x++ )
		if( a[x]==c[k] )
			ret= ( ret+rec( x+1, j, k+1 ) )%mod;

	for( int x=j;x<q;x++ )
		if( b[x]==c[k] )
			ret= ( ret+rec( i, x+1, k+1 ) )%mod;

	vis[i][j][k]= pp;

	return dp[i][j][k]= ret;
}

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		pp++;
		cin>>a>>b>>c;
		p= a.size();
		q= b.size();
		r= c.size();
		
		cout<< rec( 0, 0, 0 ) <<"\n";
	}
}