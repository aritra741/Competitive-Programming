#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mx 100007
using namespace std;

int nxt[mx];

int main()
{
	fast;

	int n,q;
	cin>>n>>q;

	int arr[n+5];
	std::vector<int> inc, dec;

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	for( int i=2;i<n;i++ )
		if( (arr[i]>arr[i-1] and arr[i]>arr[i+1]) )
			dec.push_back(i);
		else if( (arr[i]<arr[i-1] and arr[i]<arr[i+1]) )
			inc.push_back(i);

	nxt[n-1]= n;

	for( int i=n-2;i>=1;i++ )
	{
		if( arr[i]>arr[i+1] )
			if( arr[i+1]>arr[i+2] )
				nxt[i]= nxt[i+1];
			else
				nxt[i]= i+1;

		else
			if( arr[i+1]<arr[i+2] )
				nxt[i]= nxt[i+1];
			else
				nxt[i]= i+1;
	}

	while(q--)
	{
		int l,r;
		cin>>l>>r;

		int baare= 0, kome= 0;
		int pos= min(r,nxt[l])+1;

		if( arr[l]>arr[l+1] )
			kome++;
		else
			baare++;

		int pos1= lower_bound( dec.begin(), dec.end(), pos )-dec.begin();
		int pos2= upper_bound( dec.begin(), dec.end(), r-1 )-dec.begin();
			
	}
}