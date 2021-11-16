#include<bits/stdc++.h>
using namespace std;

bool cmp( string &a, string &b )
{
	return a+b<b+a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	std::vector<string> v;

	for( int i=0;i<n;i++ )
	{
		string s="";
		int len= rand()%20;

		for( int i=0;i<max(1,len);i++ )
			s.push_back('a'+rand()%25);
		v.push_back(s);
		cout<<s<<endl;
	}

	std::vector<string> vv;

	sort( v.begin(), v.end(), cmp );

	for( int i=0;i<k;i++ )
		vv.push_back(v[i]);

	// for( int i=0;i<k;i++ )
	// {
	// 	sort( v.begin(), v.end(), cmp );
	// 	reverse( v.begin(), v.end() );
	// 	vv.push_back(v.back());
	// 	v.pop_back();
	// 	reverse( v.begin(), v.end() );
	// }

	sort( v.begin(), v.end(), cmp );

	for( int i=0;i<k;i++ )
		cout<<v[i];

	cout<<endl;

	string ans= "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	sort( v.begin(), v.end() );

	do{

		string s="";

		for( int i=0;i<k;i++ )
			s+= v[i];

		ans= min(ans,s);

	}while( next_permutation(v.begin(),v.end()) );


	cout<<ans<<endl;

	// for( auto x: vv )
	// 	cout<<x;
}