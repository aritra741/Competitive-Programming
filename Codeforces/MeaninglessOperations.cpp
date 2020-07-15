#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v;
vector<ll> ::iterator it;
int cnt;

void pre()
{
    v.push_back(3);
    cnt++;

    ll add= 0;
    bool Switch= 0;

    for(int i=3; i<33554435; i++)
    {
        if( v[cnt-1]==i )
            add= i, Switch= 1;

        else if(Switch)
            v.push_back(i+add),
            Switch= 0,
            cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int q;
    cin>>q;

    while(q--)
    {
        int n;
        cin>>n;

        it= lower_bound( v.begin(), v.end(), n );
        int pos= it-v.begin();

        if(v[pos]!=n)
            cout<< v[pos] <<endl;

        else
        {
            int out= 1;
            for(int i=2; i<=sqrt(n); i++)
                if(n%i==0)
                {
                    out= n/i;
                    break;
                }
            cout<< out <<endl;
        }
    }
}
