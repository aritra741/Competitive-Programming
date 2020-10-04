#include <bits/stdc++.h>
#define mx 2007
using namespace std;

int ax[mx], ay[mx], bx[mx], by[mx];
int val[1000007];

int main()
{
	int n,m;
	cin>>n>>m;

	for( int i=0;i<n;i++ )
		cin>>ax[i]>>ay[i];
	for( int i=0;i<m;i++ )
		cin>>bx[i]>>by[i];
	
	for( int i=0;i<n;i++ )
	{
		int mxx, mxy;
		for( int j=0;j<m;j++ )
		{
			if( bx[j]>=ax[i] and by[j]>=ay[i] )
				mxx= bx[j]-ax[i]+1,
				mxy= by[j]-ay[i]+1,
				val[mxx]= max( val[mxx], mxy );;
		}
	}

	int ans= 1e9, ekhon= 0;

	for( int i=1000007;i>=0;i-- )
	{
		ans= min( ans, i+ekhon );
		ekhon= max( ekhon, val[i] );
	}

	cout<< ans <<"\n";
}