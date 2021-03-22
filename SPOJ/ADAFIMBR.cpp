#include <bits/stdc++.h>
#define mx 3000000
using namespace std;

int fib[50];
int dp[mx];

void init()
{
	fib[0] = fib[1] = 1;

	for ( int i = 2;; i++ )
		if ( fib[i - 1] + fib[i - 2] >= mx )
			break;
		else
			fib[i] = fib[i - 1] + fib[i - 2];

	int b= 0;
	for( int i=0;i<mx;i++ )
	{
		int ret= 0;
		set<int>st;

		for( int j=0;;j++ )
			if(fib[j]>i or !fib[j])
				break;
			else
				st.insert(dp[i-fib[j]]);

		while(st.find(ret)!=st.end())
			ret++;

		b= max(b,ret);
		dp[i]= ret;
	}
}

int main()
{
	init();

	int n;
	scanf("%d", &n);

	int x;
	int ans= 0;

	for( int i=0;i<n;i++ )
	{
		scanf("%d", &x);
		ans^= dp[x];
	}

	if(ans)
		printf("Ada\n");
	else
		printf("Vinit\n");
}