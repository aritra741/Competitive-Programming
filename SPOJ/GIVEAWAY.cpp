#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pii,null_type,less<pii>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii,null_type,less_equal<pii>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
ordered_set st[730];
 
int main()
{
	int n;
	scanf("%d", &n);
 
	int arr[n+5];
 
	int sq= 720;
 
	for( int i=0;i<n;i++ )
	{
		scanf("%d", &arr[i]);
		int block= i/sq;
 
		st[block].insert({arr[i],i});
	}
 
	int q;
	scanf("%d", &q);
 
	while(q--)
	{
		int tp;
		scanf("%d", &tp);
 
		if(tp)
		{
			int a,b;
			scanf("%d %d", &a, &b);
 
			a--;
 
			int block= a/sq;
			st[block].erase( st[block].lower_bound({arr[a],-1}) );
			st[block].insert({b,a});
			arr[a]= b;
		}
 
		else
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
 
			a--, b--;
 
			int i= a;
			int ans= 0;
 
			for( ;i<=b and i%sq;i++ )
				if( arr[i]>=c )
					ans++;
 
			for( ;i+sq<=b;i+=sq )
				ans+= sq-st[i/sq].order_of_key({c,-1});
 
			for( ;i<=b;i++ )
				if( arr[i]>=c )
					ans++;
 
			printf("%d\n", ans);
		}
	}
}