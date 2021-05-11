#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,p;
		cin>>n>>p;

		int x,y=0,idx=-1;
		int mx= 0, mn= 2e9;

		for( int i=0;i<n;i++ )
		{
			cin>>x;

			mx= max(mx,x);
			mn= min(mn,x);
		
			if(p%x)
				y= x, idx= i;
		}

		if(!y)
			cout<<"NO\n";
		else
		{
			cout<<"YES ";

			for( int i=0;i<n;i++ )
			{
				if(i==idx)
					cout<< (p/y)+1;
				else
					cout<<"0";

				if(i==n-1)
					cout<<"\n";
				else
					cout<<" ";
			}
		}
	}
}