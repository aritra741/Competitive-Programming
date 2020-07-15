#include <bits/stdc++.h>
#define ll long long
#define MX 10007
using namespace std;

bool arr[MX];
vector <int> prime;

ll power( ll x, ll y )
{
    ll res=1;

    while(y>0)
    {
        if( y & 1 )
            res*=x;
        y=y>>1;
        x*=x;
    }

    return res;
}

void sieve()
{
    arr[0]=arr[1]=1;
    prime.push_back(2);

    for(int i=3; i<MX; i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(int j=i*i; j<MX; j+=i)
                arr[1]=1;
        }
    }

}

string multiply( string a, int b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}

int main()
{
    sieve();
    int sz=prime.size();

    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n;
        scanf("%d", &n);

        map<int, ll> mp;
        map<int, ll> ::iterator it;

        for(int i=0; i<n; i++)
        {
            int l;
            scanf("%d", &l);

            for(int j=0; j<sz and prime[j]*prime[j]<=l; j++)
            {
                ll cnt=0;

                while( l%prime[j]==0 )
                {
                    l/=prime[j];
                    cnt++;
                }

                if(cnt)
                    mp[prime[j]]= max( mp[prime[j]], cnt );
            }

            if(l!=1)
                mp[l]= max( mp[l], 1LL );

        }

        string ans;
        ans= "1";

        for(it=mp.begin(); it!=mp.end(); it++)
        {
            int num= it->first;
            int occur= it->second;
            for(int p=0;p<occur;p++)
                ans=multiply(ans, num);
        }
        reverse(ans.begin(),ans.end());
        printf("Case %d: ", t);
        cout<<ans<<endl;

    }
}
