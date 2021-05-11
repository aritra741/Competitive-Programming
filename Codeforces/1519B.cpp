#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m,k;
		cin>>n>>m>>k;

		int tot1= m-1+m*(n-1);
		int tot2= n*(m-1)+(n-1);
		
		// cout<<tot1<<" "<<tot2<<endl;

		if(k>=min(tot1,tot2) and k<=max(tot1,tot2))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}