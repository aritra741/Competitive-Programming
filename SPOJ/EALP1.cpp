#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	int t= 1;

	while(tc--)
	{
		int n;
		scanf("%d", &n);

		int ans= 0;
		int arr[n+5];

		for( int i=0;i<n;i++ )
		{
			int x;
			scanf("%d", &x);

			arr[i]= x;
			ans^= x;
		}

		printf("Case %d: ", t++);
		int cnt= 0;

		if(!ans)
			printf("0\n");
		else
		{
			for( int i=0;i<n;i++ )
				if( (arr[i]^ans)<=arr[i] )
					cnt++;

			printf("%d\n", cnt);
		}
	}
}