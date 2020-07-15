#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<ll> v(n);
    vector<ll> ::iterator it;

    for(int i=0;i<n;i++)
        cin>>v[i];

    sort( v.begin(), v.end() );

    int cnt= 1;
    ll tot= v[0];
    v[0]= 0;

    for(int i=1;i<n;i++)
    {
        it= lower_bound( v.begin(), v.end(), tot );
        if(it==v.end())
            continue;
        int pos= it-v.begin();
        tot+=v[pos];
        v[pos]= 0;
        cnt++;
    }

    cout<<cnt<<endl;
}
