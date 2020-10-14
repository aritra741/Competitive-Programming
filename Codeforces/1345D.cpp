#include <bits/stdc++.h>
using namespace std;

string s[1007];
bool shadarow, shadacol, vis[1007][1007], kalo;
int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};
int n,m;

bool isValid( int x, int y )
{
	if(x<0 or y<0)
		return 0;
	if(x>=n or y>=m)
		return 0;
	if(s[x][y]=='.')
		return 0;
	if(vis[x][y])
		return 0;
	return 1;
}

void dfs( int x, int y )
{
	vis[x][y]= 1;
	for( int i=0;i<4;i++ )
	{
		int u= x+dx[i];
		int v= y+dy[i];
		
		if( isValid(u,v) )
			dfs(u,v);
	}
}

int main()
{
	cin>>n>>m;

	for( int i=0;i<n;i++ )
		cin>>s[i];

	for( int i=0;i<n;i++ )
	{
		bool f= 1;
		for( int j=0;j<m;j++ )
			if( s[i][j]=='#' )
				f= 0;
		if(f)
			shadarow= 1;
	}

	for( int i=0;i<m;i++ )
	{
		bool f= 1;
		for( int j=0;j<n;j++ )
			if( s[j][i]=='#' )
				f= 0;
		if(f)
			shadacol= 1;
	}
	

	bool valid= 1;
	for( int i=0;i<n;i++ )
	{
		bool f= 0;

		for( int j=0;j<m;j++ )
		{
			if(s[i][j]=='#')
			{
				kalo= 1;
				if(!f)
					f= 1;
				else if( j and s[i][j-1]=='.' )
				{
					valid= 0;
					break;
				}
			}
		}


		if(!f and !shadacol)
			valid= 0;
		else if(!f and kalo and m==1 )
			valid= 0;
	}

	for( int i=0;i<m;i++ )
	{
		bool f= 0;

		for( int j=0;j<n;j++ )
		{
			if(s[j][i]=='#')
			{
				kalo= 1;
				if(!f)
					f= 1;
				else if( j and s[j-1][i]=='.' )
				{
					valid= 0;
					break;
				}
			}
		}

		if(!f and !shadarow)
			valid= 0;
		else if(!f and kalo and n==1 )
			valid= 0;
	}

	if(!valid)
		return cout<<"-1\n", 0;

	int ans= 0;

	for( int i=0;i<n;i++ )
		for( int j=0;j<m;j++ )
			if( isValid(i,j) )
				ans++, dfs(i,j);

	cout<< ans <<"\n";
}