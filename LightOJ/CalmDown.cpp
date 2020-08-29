#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	for(int i=1;i<=tc;i++)
	{
		double R;
		int n;
		cin>>R>>n;
		double th=2*acos(0.0)/n;
		double theta=sin(th);
		double lhs=theta*R/(1+theta);
		cout<<"Case "<<i<<": "<<setprecision(12)<<fixed<<lhs<<endl;
	}
}
