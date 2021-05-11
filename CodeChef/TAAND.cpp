#include <bits/stdc++.h>
#define mx 300007
using namespace std;

bool baad[mx];

int main()
{
	int n;
	scanf("%d", &n);

	int ans= 0;

	int arr[n+5];

	for( int i=0;i<n;i++ )
		scanf("%d", &arr[i]);

	for( int i=30;i>=0;i-- )
	{
		int cnt= 0;
		for( int j=0;j<n;j++ )
			if( !baad[j] and (arr[j]&(1<<i)) )
				cnt++;

		if( cnt<2 )
			continue;

		ans+= 1<<i;

		for( int j=0;j<n;j++ )
			if( !baad[j] and !(arr[j]&(1<<i)) )
				baad[j]= 1;
	}

	printf("%d\n", ans);
}