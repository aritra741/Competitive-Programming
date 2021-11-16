#include <bits/stdc++.h>
using namespace std;

int brr[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int arr[107];
int n;
int f[60];

int fact( int x )
{
	int mask= 0;
	for( int i=0;i<17;i++ )
		if( x%brr[i]==0 )
			mask|= (1<<i);

	return mask;
}

int dp[111][(1 << 17) + 1];
std::vector<int> v;

void rec( int i, int mask )
{
	if( i>=n )
		return;

	int ans= arr[i]-1+dp[i+1][mask], val= 1;

	for( int j=1;j<60;j++ )
	{
		if( !(f[j]&mask) )
		{
			if( dp[i+1][mask^f[j]]+abs(j-arr[i])<ans )
				ans= abs(j-arr[i])+dp[i+1][mask^f[j]], val= j;
		}
	}

	v.push_back(val);

	rec( i+1, mask^f[val] );
}  

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for( int i=0;i<n;i++ )
		cin>>arr[i];

	for( int i=59;i>=1;i-- )
		f[i]= fact(i);

	for( int i=n-1;i>=0;i-- )
	{
		int k=i%2;

		for( int mask=0;mask<(1<<17);mask++ )
		{
			dp[i][mask]= arr[i]-1+dp[i+1][mask];
				
			for( int j=1;j<=59;j++ )
			{
				if(  !(f[j]&mask)  )
					if( dp[i][mask]>abs(arr[i]-j)+dp[i+1][mask^f[j]] )
					{
						dp[i][mask]= abs(arr[i]-j)+dp[i+1][mask^f[j]];
					}
			}
		}
	}

	rec(0,0);

	for( auto x: v )
		cout<<x<<" ";
}