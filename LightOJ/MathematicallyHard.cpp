#include <bits/stdc++.h>
#define ull unsigned long long
#define MAX 5*1000000+1
using namespace std;

int num[MAX];
ull sum[MAX];
void sieve(void)
{
    sum[0]=0;
    sum[1]=0;
    num[0]=1;
    num[1]=1;
    for(int i=2;i<MAX;i++)
        sum[i]=i;
	for(int i=2;i<MAX;i++)
		{
			if(num[i]==0)

					{


						for(int j=1;i*j<=MAX;j++)
							{
								if(num[i*j]==0)
									num[i*j]=1;
                                sum[i*j]*=(i-1);
                                sum[i*j]/=i;


							}
					}
		}
		cout<<sum[6]<<endl;
    for(int i=2;i<MAX;i++)
    {
        sum[i]*=sum[i];
        sum[i]+=sum[i-1];
    }
//for(int n=2;n<MAX;n++)
//            {
//
//		int temp=n;
//		double inittemp=n;
//		for(int j=0;j<cnt-1 && prime[j]<=temp;j++)
//		{
//
//
//			if(temp%prime[j]==0)
//			{
//
//			while(temp%prime[j]==0)
//				{
//
//					temp/=prime[j];
//
//				}
//			inittemp*=(1-1.00/prime[j]);
//
//			}
//
//		}
//		sum[n]=inittemp*inittemp;
//
//		}

}

int main()
{
	int tc,p,q;
	cin>>tc;
	sieve();
	for(int i=1;i<=tc;i++)
	{


		scanf("%d %d", &p, &q);
		printf("Case %d: %llu\n", i, sum[q]-sum[p-1]);
	}

}
