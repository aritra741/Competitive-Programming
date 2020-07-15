#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;
vector <pii> divs;
int num[MAX];
bool cmp(pii a, pii b)
{

	if(a.first < b.first) {
		return 1;
	}

	if(a.first > b.first) {
		return 0;
	}

	if(a.second > b.second) {
		return 1;
	}

	return 0;

}

//class piiComp
//{
//public:
//	bool operator()(const pii& l, const pii& r)
//	{
//		return operator<(l,r);
//	}
//};
void sieve(void)
{

	num[0]=1;
	num[1]=1;

	for(int i=2;i<MAX;i++)
		{

			if(num[i]==0)
			{
				for(int j=2;i*j<MAX;j++)
				{
					if(num[i*j]==0)
						num[i*j]=1;
				}
			}

}
}
void divCount(void)
{

	divs.push_back(make_pair(1,1));
	for(int i=2;i<MAX;i++)
	{
		int cnt=0;
		int ans=1;
		if(num[i]==0)
		{

			divs.push_back(make_pair(2, i));
			continue;
		}

		for(int j=2;j<=i;j++)
		{
            cnt=0;
			if(num[j]==0 && i%j==0)
			{
				int temp=i;
				while(temp%j==0)
				{
					temp/=j;
					cnt++;
				}
				if(cnt!=0)ans*=cnt+1;


			}


		}
		divs.push_back(make_pair(ans, i));

	}
	sort(divs.begin(), divs.end(), cmp);
}

int main()
{
	int tc;
	cin>>tc;
	sieve();
	divCount();
	for(int i=1;i<=tc;i++)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", i, divs[n-1].second);
    }
//	for(int i=1;i<=tc;i++)
//	{
//
//	}

}
