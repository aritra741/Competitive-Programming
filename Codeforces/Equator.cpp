#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	int h=ceil( (double)sum/2);
	int temp=0;
	for(int i=0;i<n;i++)
	{
		temp+=arr[i];
		if(temp>=h)
		{
			cout<<i+1<<endl;
			break;
		}
	}

}
