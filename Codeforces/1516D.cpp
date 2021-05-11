#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 100007
using namespace std;

int arr[mx], jump[mx], pore[mx], last[mx];
std::vector<int> v[mx], dv[mx];
int bl[mx];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,q;
	cin>>n>>q;

	int sq= 300;

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	for( int i=1;i<=n;i++ )
	{
		int x= arr[i];

		for( int j=2;j*j<=x;j++ )
		{
			if( x%j==0 )
			{
				v[j].push_back(i);
				dv[i].push_back(j);

				while(x%j==0)
					x/= j;
			}
		}

		if(x>1)
			v[x].push_back(i), dv[i].push_back(x);
	}

	int totBlock= 0;

	for( int i=n;i>=1;i-- )
	{
		int mn= n+1;

		for( auto x: dv[i] )
		{
			int pos= upper_bound( v[x].begin(), v[x].end(), i )-v[x].begin();

			if( pos>=v[x].size() )
				continue;
 
			mn= min( mn, v[x][pos] );
		}

		if(i<n)
			mn= min(mn, pore[i+1]);

		int block= (i-1)/sq;
		totBlock= max( totBlock, block );

		bl[block]++;
		pore[i]= mn;

		// cout<<i<<" "<<pore[i]<<endl;
	}

	for( int i=totBlock;i>=0;i-- )
	{
		if( !bl[i] )
			continue;
		
		for( int j=bl[i]-1;j>=0;j-- )
		{
			int idx= i*sq+j+1;
			int p= pore[idx];
			int nxtBlock= (p-1)/sq;
			
			if( nxtBlock>i or p>n or idx==n )
				jump[idx]= 1, last[idx]= idx;
			else
				jump[idx]= jump[p]+1, last[idx]= last[p];
			// cout<<idx<<endl;
			// if( !last[idx] )
			// 	cout<<idx<<" "<<p<<" "<<pore[idx]<<" "<<jump[idx]<<" "<<i<<endl;
		}
	}

	while(q--)
	{
		int l,r;
		cin>>l>>r;

		int block= (l-1)/sq;
		int ans= 0;
		int x= l;

		while(x<=r)
		{
			block= (x-1)/sq;

			if( block>=((r-1)/sq) )
				break;

			// cout<<x<<" "<<pore[x]<<endl; 
			ans+= jump[x];
			
			if( ((pore[x]-1)/sq)>block )
				x= pore[x];
			else
				x= pore[last[x]];
		}

		while(x<=r)
		{
			// cout<<" "<< x<<" "<<pore[x]<<endl;
			x= pore[x];
			ans++;
		}

		cout<< ans <<"\n";
	}
}