// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define mx 3007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main()
{

	cout<<"3000\n";

	for( int i=0;i<3000;i++ )
	{
		for( int j=0;j<5;j++ )
			cout<<rand()<<" ";

		cout<<endl;
	}
}