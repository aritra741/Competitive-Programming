#include <bits/stdc++.h>
using namespace std;

int mp[107], arr[200007];

int main()
{
	int n,m;
	cin>>n>>m;

	int sum= 0;
	for( int i=0;i<n;i++ )
	{
		int p;
		cin>>p;

		if(sum+p<=m)
		{
			cout<<"0 ";
			sum+= p;
			mp[p]++;
			continue;
		}

		int x= 0, cnt= 0;
		for( int j=100;j>=1;j-- )
		{
			int baki= (sum+p-m)-x;

			if(baki<=0)
				break;

			int tot= mp[j]*j;

			cnt+= min( mp[j], (baki+j-1)/j );
			x+= min( mp[j], (baki+j-1)/j )*j;

			// cout<<i+1<<" "<<j<<" "<<x<<endl;
		}

		cout<<cnt<<" ";

		mp[p]++;
		sum+= p;
	}
}