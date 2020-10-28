#include <bits/stdc++.h>
using namespace std;

set<int>ones, ultaones, zeros, ultazeros;

int main()
{
	int n;
	cin>>n;

	int zeroone= 0, onezero= 0;
	int zs= 0, os= 0, zt= 0, ot= 0;

	string s,t;
	cin>>s>>t;

	int balance= 0;

	for( int i=0;i<n;i++ )
	{
		if(s[i]=='1')
			os++;
		else
			zs++;
		if(t[i]=='1')
			ot++;
		else
			zt++;
		
		if( s[i]!=t[i] )
		{
			if( s[i]=='1' )
				balance++;
			else
				balance--;
		}

		if(balance>0)
			onezero= max( onezero, balance );
		else
			zeroone= min( zeroone, balance );
	}

	if(zs!=zt or os!=ot)
		onezero= -1, zeroone= 0;

	cout<< onezero+abs(zeroone) <<"\n";
}