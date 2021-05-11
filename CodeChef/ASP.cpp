#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

pii arr[1000007];

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		int n;
		scanf("%d", &n);

		for( int i=1;i<=n;i++ )
			scanf("%d", &arr[i].ff), arr[i].ss= i;

		sort( arr+1, arr+n+1 );

		bool f= 1;

		for( int i=1;i<=n;i++ )
			if( abs(arr[i].ss-i)>1 )
			{
				f= 0;
				break;
			}

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}