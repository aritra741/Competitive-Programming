#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m,x,y;
		cin>>n>>m>>x>>y;

		int cnt= 0;

		for( int i=0;i<n;i++ )
			for( int j=0;j<m;j++ )
				if( (i+j)&1 )
					cnt++;

		int a= max(cnt,m*n-cnt);
		int b= min(cnt,m*n-cnt);
		
		if(n*m>1)
			x= min(x,y);

		int ans1= a*x+b*(min(x,y-x));
		int ans2= a*(min(x,y-x))+b*x;
		
		cout<< max(ans1,ans2) <<"\n";
	}
}