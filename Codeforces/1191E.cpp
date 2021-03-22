#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	if(k+1>=n)
		return cout<<"tokitsukaze", 0;

	int z = 0, o = 0;

	for (auto c : s)
		if (c == '0')
			z++;
		else
			o++;

	for ( int i = 0; i < k - 1; i++ )
		if (s[i] == '0')
			z--;
		else
			o--;

	int a= 0, b= 0, c= 0;
	int ageyz= 0, ageyo= 0;

	int ozp[n+5], ozs[n+5], zop[n+5], zos[n+5]; 
	ozp[0]= ozs[0]= zop[0]= zos[0]= 0;
	ozp[n]= ozs[n]= zop[n]= zos[n]= 0;
	
	int last1[n+5], last0[n+5], next1[n+5], next0[n+5];
	
	for( int i=1;i<n;i++ )
	{
		if(s[i]=='1' and s[i-1]=='0')
			ozp[i]= ozp[i-1]+1;
		else
			ozp[i]= 0;
		else if(s[i]=='0' and s[i-1]=='1')
			zop[i]= zop[i-1]+1;
		else
			zop[i]= 0;
	}

	last1[0]= last0[0]= next1[n-1]= next0[n-1]= -5;

	for( int i=1;i<n;i++ )
	{
		if(s[i-1]=='1')
			last1[i]= i-1;
		else
			last1[i]= last1[i-1];
		
		if(s[i-1]=='0')
			last0[i]= i-1;
		else
			last0[i]= last0[i-1];		
	}

	for( int i=n-2;i>=0;i-- )
	{
		if(s[i+1]=='1')
			next1[i]= i+1;
		else
			next1[i]= -5;

		if(s[i+1]=='0')
			next0[i]= i+1;
		else
			next0[i]= next0[i+1];		
	}

	for( int i=n-2;i>=0;i-- )
	{
		if(s[i]=='1' and s[i+1]=='0')
			ozs[i]= ozs[i+1]+1;
		else
			ozs[i]= 0;
		else if(s[i]=='0' and s[i+1]=='1')
			zos[i]= zos[i+1]+1;
		else
			zos[i]= 0;
	}

	for ( int i = k - 1; i < n; i++ )
	{
		c++;
		if (s[i] == '0')
			z--;
		else
			o--;

		if (i - k >= 0)
			if (s[i-k] == '0')
				ageyz++;
			else
				ageyo++;

		if(!ageyo and !o)
			a++;
		else if(!ageyz and !z)
			a++;
		else if( ageyz<=1 and !ageyo and !z and o and min( n-i+1, i-k+1 )<=k )
			b++;
		else if( !ageyz and ageyo<=1 and z and !o and min( n-i+1, i-k+1 )<=k )
			b++;
		else if( oz==1 and !z and  )

	}

	cout<<a<<" "<<b<<" "<<c<<endl;

	if(a)
		cout<<"tokitsukaze";
	else if(b==c)
		cout<<"quality";
	else
		cout<<"once again";
}