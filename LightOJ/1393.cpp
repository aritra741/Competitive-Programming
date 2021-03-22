#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		int n,m;
		scanf("%d %d", &n, &m);

		int arr[n+5][m+5];

		int p= (n-1+m-1)%2, ans= 0;

		for( int i=0;i<n;i++ )
			for( int j=0;j<m;j++ )
			{
				scanf("%d", &arr[i][j]);

				if((i+j)%2!=p)
					ans^= arr[i][j];
			}

		printf("Case %d: ", t );

		if(ans)
			printf("win\n");
		else
			printf("lose\n");
	}
}