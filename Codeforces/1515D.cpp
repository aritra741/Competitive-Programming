#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,l,r;
		cin>>n>>l>>r;

		int arr[n+5];

		map<int,int>mp1,mp2;
		int totl= 0, totr= 0;

		for( int i=0;i<l;i++ )
			cin>>arr[i], mp1[arr[i]]++, totl++;

		int ans= 0;
		
		for( int i=l;i<n;i++ )
		{
			cin>>arr[i];

			if(mp1.find(arr[i])!=mp1.end())
			{
				mp1[arr[i]]--;
				totl--;

				if(!mp1[arr[i]])
					mp1.erase(arr[i]);
				// cout<<" "<<mp1.size()<<endl;
			}
			else
				mp2[arr[i]]++, totr++;
		}

		priority_queue<pii, vector<pii>, greater<pii> >pq;

		if( totl>totr )
			swap(totl,totr), mp1.swap(mp2);

		for( auto x: mp2 )
			pq.push(pii(x.second, x.first));

		for( auto x: mp1 )
		{
			if(pq.empty())
				break;

			for( int i=0;i<x.second and pq.size();i++ )
			{
				pii u= pq.top();
				pq.pop();

				if( u.first>1 )
					pq.push(pii(u.first-1, u.second));

				mp1[x.first]--;
				ans++;

				// cout<<" "<<x.first<<" "<<u.second<<" "<<endl;
			}
		}	

		while(!pq.empty())
		{
			pii x= pq.top();
			pq.pop();

			for( int i=0;i<x.first;i++ )
			{
				if( i+1<x.first )
				{
					ans++;
					i++;
				}
				else
					rem++;

				// cout<<x.first<<" "<<rem<<endl;
			}
		}

		// cout<<ans<<" "<<rem<<endl;
		cout<< ans+rem <<"\n";
	}
}