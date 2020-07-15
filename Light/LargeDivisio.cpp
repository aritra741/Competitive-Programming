#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void LargeDiv(string s, int div, int tc)
{
	double ans=0;

    int len=s.length();
	for(int i=0;i<len;i++)
	{
		ans=fmod((ans*10)+ (ull)(s[i]-'0') , div);
        	}

	if(ans==0)
		printf("Case %d: divisible\n", tc);
	else
		printf("Case %d: not divisible\n", tc);


}

int main()
{
	int tc;
	cin>>tc;
	for(int i=1;i<=tc;i++)
{
	string s;
	int div;
	cin>>s>>div;
	if(s[0]=='-')
	s.erase(s.begin(), s.begin()+1);
	LargeDiv(s, div, i);



}


}
