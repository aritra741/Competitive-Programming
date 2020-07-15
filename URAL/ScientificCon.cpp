#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> pii;
bool cmp(pii a, pii b)
{

	if(a.first < b.first) {
		return 1;
	}

	if(a.first > b.first) {
		return 0;
	}

	if(a.second > b.second) {
		return 0;
	}
}
int main()
{

	long long n;
	int ending=0;
	int cnt=0;
	cin>>n;
	vector<pii> pq;
	vector<pii> :: iterator it;
	for(int i=0;i<n;i++)
    {
        int p,q;
        cin>>p>>q;
        pq.push_back(pii(q,p));
    }
    sort(pq.begin(), pq.end(), cmp);
    for(it=pq.begin();it!=pq.end();it++)
    	{
    		if(it->second>ending)
    		{
    			ending=it->first;
    			cnt++;
    		}
    	}

    cout<<cnt<<endl;



}
