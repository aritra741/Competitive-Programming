#include <bits/stdc++.h>
#define mx 20000007
#define ll long long
using namespace std;

ll ans[mx];

void init()
{
	for( int i=1;i<mx;i++ )
		for( int j=i;j<mx;j+=i )
			ans[j]+= i;

	ans[1]= 0;

	for( int i=1;i<mx;i++ )
		ans[i]+= ans[i-1];
}

int main()
{
	init();
	int n;

	while(scanf("%d", &n)==1 and n)
		printf("%lld\n", ans[n]);
}