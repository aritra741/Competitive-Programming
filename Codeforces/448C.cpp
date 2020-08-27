#include <bits/stdc++.h>
using namespace std;

int arr[5007];

int rec( int l, int r, int d )
{
	if(l>r)
		return 0;

	int pos= l;

	for( int i=l;i<=r;i++ )
		if(arr[pos]>arr[i])
			pos= i;

	int ret= r-l+1;
	return min( ret, arr[pos]-d+rec( l, pos-1, arr[pos] )+ rec( pos+1, r, arr[pos] ) ); 
}

int main()
{
	int n;
	cin>>n;

	for( int i=0;i<n;i++ )
		cin>>arr[i];

	cout<< rec( 0, n-1, 0 ) <<endl;

}