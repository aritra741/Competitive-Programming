#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll, ll>
#define ppll pair <ll, pll>
using namespace std;

vector <ppll> v;

bool cmp(const ppll &a, const ppll &b)
{
    if(a.second.first==b.second.first)
        return a.second.second<b.second.second;
    return a.second.first>b.second.first;
}

int main()
{
    ll n;
    cin>>n;

    for(int i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;

            v.push_back( ppll(y-x, pll(x,y)) );
        }

    sort(v.begin(),v.end(), cmp);
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i].second.first<<" "<<v[i].second.second<<endl;

    ll mxx=-1,mny=10000000000;

    for(int i=1;i<n;i++)
    {
        mxx= max( v[i].second.first, mxx );
        mny= min( v[i].second.second, mny );
    }

    cout<< abs(mxx-mny) <<endl;

}


