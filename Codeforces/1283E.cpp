#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 200007
using namespace std;

int n;
int arr[mx];

int rec1( int i, int st )
{
	if(i>n)
		return 0;

	int ret= 0;

	if(st==0)
	{
		ret= max( ret, 1+rec1( i+1, 2 ) );
		
		int now1= 1;

		if(i>1 and arr[i-1]==arr[i]-1 )
			now1--;

		ret= max( ret, now+rec1( i+1, 1 ) );
	}
	else if( st==1 )
	{
		ret= max( ret, 1+rec1( i+1, 0 ) );
		ret= max( ret, 1+rec1( i+1, 2 ) );
		ret= max( ret, 1+rec1( i+1, 1 ) );	
	}
	else
	{
		ret= max( ret, 1+rec1( i+1, 1 ) );
		ret= max( ret, 1+rec1( i+1, 2 ) );
		
		int now= 1;

		if(i>1 and arr[i-1]==arr[i]-1 )
			now--;

		ret= max( ret, now+rec1( i+1, 0 ) );
	}

	return ret;
}

int main()
{
	cin>>n;

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	cout<< rec1( 1, 4 ) ;
}