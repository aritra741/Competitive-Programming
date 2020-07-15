#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bigmod(ll n, ll p)
{
    n%=1000;
    ll res=1;

    while(p>0)
    {
        if(p&1)
            res= ((res%1000)*(n%1000))%1000;
        p/=2;

        n= ((n%1000)*(n%1000))%1000;
    }

    return res%1000;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        printf("Case %d: ", t);

        double t1= k*log10(n);
        stringstream ss;
        string s;
        ss<<setprecision(8)<<fixed<<t1;
        ss>>s;
        string tp;
        bool flag=0;

        int len= s.size();

        for(int i=0;i<len;i++)
        {
            if(flag)
                tp.push_back(s[i]);
            if(s[i]=='.')
                flag=1;
        }

        ss.str( std::string() );
        ss.clear();

        ss<<tp;
        double num;
        ss>>num;
        len= tp.size();
        double ex= num/pow(10, len);

        double ans= pow(10, ex);

        ss.str( std::string() );
        ss.clear();
        ss<<setprecision(8)<<fixed<<ans;
        ss>>s;

        int cnt=0;
        len= s.size();

        for(int i=0;i<len;i++)
        {
            if(s[i]!='.')
            {
                printf("%c",s[i]);
                cnt++;
            }

            if(cnt==3)
                break;
        }

        printf(" ");

        printf("%03lld\n", bigmod( n,k ));
    }
}
