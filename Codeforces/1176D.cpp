#include<bits/stdc++.h>
#define ll long long
#define mx 2800007
using namespace std;

int arr[mx];
int prime[mx];
int cnt;

void sieve()
{
    for( ll i=2; i<mx; i++ )
    {
        if(!arr[i])
        {
            prime[cnt++]= i;

            for( ll j=i*2; j<mx; j+=i )
                if( !arr[j] )
                    arr[j]= i;
        }
    }
}

multiset<int,greater<int>>st;
vector<int>v;

int main()
{
    sieve();

    int n;
    scanf("%d", &n);

    n*= 2;

    for( int i=0; i<n; i++ )
    {
        int p;
        scanf("%d", &p);

        st.insert(p);
    }

    for( auto x: st )
    {
        int p= x;

        if( !arr[p] )
        {
            int pos= lower_bound(prime,prime+cnt,p)-prime;

            v.push_back(pos+1);
            st.erase( st.find(pos+1) );
        }
        else
            v.push_back(p),
            st.erase( st.find(p/arr[p]) );
    }

    for( int i=0;i<v.size();i++ )
        printf("%d ", v[i]);
}
