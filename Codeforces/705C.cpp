#include<bits/stdc++.h>
#define mx 300007
#define sf(x) scanf("%d", &x)
using namespace std;

vector<int>v;

int main()
{
    int n,q;
    sf(n);
    sf(q);

    int t= 0;
    int last= 0;
    int ans= 0;

    while(q--)
    {
        int tp;
        sf(tp);

        if(tp==1)
        {
            t++;
            int x;
            sf(x);

            v[x].push_back(t);

            ans++;
        }
        else if(tp==2)
        {
            int x;
            sf(x);

            int pos= upper_bound( v[x].begin(), v[x].end(), last );
            ans+= v[x].size()-pos;
            v[x].clear();
        }
        else
        {
            int k;
            sf(k);


        }
    }
}

