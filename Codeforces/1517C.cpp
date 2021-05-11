#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int arr[507][507];

int main()
{
	fast;

	int n;
	cin>>n;

	for( int i=1;i<=n;i++ )
		cin>>arr[i][i];

	bool f= 1;

	for( int i=1;i<=n;i++ )
	{
		int x= arr[i][i];
		int cnt= 1, last= i;
 
		for( int j=i-1;j>=1 and cnt<x;j-- )
			if( !arr[i][j] )
				arr[i][j]= x, cnt++, last= j;

		if(cnt==x)
			continue;

		int fir= last;
		for( int j=i+1;j<=n and cnt<x;j++ )
		{
			for( int k=fir;k>=1 and cnt<x;k-- )
			{
				if( !arr[j][k] )
				{
					fir= k;
					arr[j][k]= x, cnt++;
				}
				else
					break;
			}

		}


		if(cnt<x)
		{
			// cout<<"-1";
			// f= 0;
			// break;
		}

	}

	// if(!f)
	// 	return 0;

	for( int i=1;i<=n;i++ )
		for( int j=1;j<=i;j++ )
		{
			cout<< arr[i][j] <<" ";
			
			if(j==i)
				cout<<"\n";	
		}
}