#include <bits/stdc++.h>
#define ull unsigned long long
#define INF 10000007
using namespace std;

int RangeMin(int *stMin, int l, int r, int ql, int qr, int current)
{
	if(ql>r || qr<l)
		return INF;
	if(ql<=l && qr>=r)
		return stMin[current];
	int mid=l+(r-l)/2;
	return min( RangeMin(stMin,l, mid, ql, qr, current*2+1), RangeMin(stMin,mid+1, r, ql, qr, current*2+2) );
}

int constructUtilMIN(int arr[], int *stMin, int l, int r, int current)
{
	if(l==r)
	{
		stMin[current]=arr[l];
		return arr[l];
	}
	int mid=l+(r-l)/2;
	stMin[current]=min( constructUtilMIN(arr, stMin, l, mid, current*2+1), constructUtilMIN(arr, stMin, mid+1, r, current*2+2) );
	return stMin[current];
}

int constructUtilMAX(int arr[], int *stMax, int l, int r, int current)
{
	if(l==r)
	{
		stMax[current]=arr[l];
		return arr[l];
	}
	int mid=l+(r-l)/2;
	stMax[current]=max( constructUtilMAX(arr, stMax, l, mid, current*2+1), constructUtilMAX(arr, stMax, mid+1, r, current*2+2) );
	return stMax[current];
}

int *ConstructSTMin(int arr[], int n)
{
	int MAX_HEIGHT=(int)ceil(log2(n));
	int MAX_ELEMENT=2*(int)(pow(2, MAX_HEIGHT))-1;

	int *stMin=new int[MAX_ELEMENT];

	constructUtilMIN(arr, stMin, 0, n-1, 0);

	return stMin;
}

int *ConstructSTMAx(int arr[], int n)
{
	int MAX_HEIGHT=(int)ceil(log2(n));
	int MAX_ELEMENT=2*((int)pow(2, MAX_HEIGHT))-1;

	int *stMax= new int[MAX_ELEMENT];

	constructUtilMAX(arr, stMax, 0, n-1, 0);
	return stMax;
}

int RangeMax(int *stMax, int l, int r, int ql, int qr, int current)
{
 if(ql>r || qr<l)
 	return 0;
 if(ql<=l && qr>=r)
 	return stMax[current];
 int mid=l+(r-l)/2;
 return max( RangeMax(stMax,l, mid, ql, qr, current*2+1), RangeMax(stMax,mid+1, r, ql, qr, current*2+2) );
}


int main()
{
	int tc;
	scanf("%d", &tc);
	for(int i=1;i<=tc;i++)
	{
		int n, q;
		scanf("%d %d", &n, &q);
		int arr[n];
		for(int j=0;j<n;j++)
			scanf("%d", &arr[j]);
		int *stMIN= ConstructSTMin(arr, n);
		int *stMAX= ConstructSTMAx(arr, n);
		int ans=0;
		for(int it=0;it<=n-q;it++)
		{
			ans=max( (abs(RangeMax(stMAX,0, n-1, it, it+q-1, 0)- RangeMin(stMIN,0, n-1, it, it+q-1, 0))), ans );

		}

		printf("Case %d: %d", i, ans);
	}
}
