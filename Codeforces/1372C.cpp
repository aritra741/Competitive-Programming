#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+5];
		int cnt= 0, pp= 0, qq= 0;

		for( int i=1;i<=n;i++ )
		{
			cin>>arr[i];

			if(arr[i]==i)
				cnt++, pp= 0;
			else
				pp++;

			if(pp==1)
				qq++;
		}

		if(cnt==n)
			cout<<"0"<<"\n";
		else if(cnt==0 or qq<2)
			cout<<"1\n";
		else
			cout<<"2\n";
	}
}