#include <bits/stdc++.h>
#define mx 200007
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

pii arr[mx];
multiset<int, greater<int> > st;
multiset<int> sec;
std::vector<int> v[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int p,n,k;
	cin>>n>>k;

	for( int i=1;i<=n;i++ )
		cin>>p, st.insert(p), sec.insert(-p);

	for( int i=1;i<=k;i++ )
		cin>>arr[i].ff, arr[i].ss= i;

	reverse( arr+1, arr+k+1 );

	int sz= 0;

	while(st.size())
	{
		int nisi= 0;
		std::vector<int> baad;
		int last= k;

        while(1)
		{
			int pos= lower_bound( arr+(k-last+1), arr+k+1, pii(nisi+1,-1) )-arr;

			if( pos>k )
				break;

			auto it= sec.lower_bound( -(k-pos+1) );

			if(it==sec.end())
                break;

			int val= -(*it);

			nisi++;
			v[sz].push_back(val);
			sec.erase( sec.find(-val) );
			st.erase( st.find(val) );
			last= val;
		}

		sz++;
	}

	cout<< sz <<"\n";

	for( int i=0;i<sz;i++ )
	{
		cout<<v[i].size()<<" ";
		for( int j=0;j<v[i].size();j++ )
			cout<< v[i][j] <<" ";

		cout<<"\n";
	}
}
