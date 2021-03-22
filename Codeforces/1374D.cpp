#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define mx 30007
#define pii pair<int,int>
#define pci pair<int,int>
#define ff first
#define ss second
#define piii pair<int,pii>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
    	ll n,k;
    	cin>>n>>k;

    	ll arr[n+5];
    	int cnt= 0;

    	for( int i=0;i<n;i++ )
    	{
    		cin>>arr[i], arr[i]%= k, arr[i]= (k-arr[i]+k)%k;
    		
    		if(arr[i])
    			cnt++;
    	}

    	if(!cnt)
    	{
    		cout<<"0\n";
    		continue;
    	}

    	map<int,ll>mp;
    	ll ans= 0;

    	for( int i=0;i<n;i++ )
    	{
    		if( mp[arr[i]] )
    			mp[arr[i]]+= k;
    		else
    			mp[arr[i]]= arr[i];
    		ans= max( ans, mp[arr[i]] ); 
    	}

    	cout<< ans+1 <<"\n";
    }
}