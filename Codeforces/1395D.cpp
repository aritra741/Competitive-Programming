#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n,d,m;
	cin>>n>>d>>m;

	int arr[n+5];

	std::vector<int> boro, chhoto;
	deque<int>dq;

	for( int i=0;i<n;i++ )
	{
		cin>>arr[i];

		if( arr[i]<=m )
			chhoto.push_back(arr[i]);
		else
			boro.push_back(arr[i]);
	}

	sort( chhoto.begin(), chhoto.end() );
	sort( boro.begin(), boro.end(), greater<int>() );

	int i= 0, j= 1;

	while(j<boro.size() and i+d-1<chhoto.size() )
	{
		dq.push_back(boro[j]);
		j++;
		int tar= i+d;

		while(i<tar)
			dq.push_back(chhoto[i]), i++;
	}

	while(i<chhoto.size())
		dq.push_front(chhoto[i]), i++;

	if(boro.size())
		dq.push_back(boro[0]);

	while(j<boro.size())
		dq.push_back(boro[j]), j++;

	assert(dq.size()==n);

	ll ans= 0;

	for( int i=0;i<n;i++ )
	{
		ans+= dq[i];

		if( dq[i]>m )
			i+= d;
	}

	cout<< ans <<endl;
}