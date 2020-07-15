#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull fact[21];

void preCalc()
{
    fact[0]=1;

    for(int i=1;i<=20;i++)
        fact[i]=fact[i-1]*i;
}

int main()
{
    preCalc();

    int ds;
    cin>>ds;

    for(int t=1;t<=ds;t++)
    {
        string s;
        cin>>s;

        map <char, int> mp;
        map <char, int> ::iterator it;
        int len= s.size();

        for(int i=0;i<len;i++)
            mp[ s[i] ]++;

        ull ans= fact[len];

        for(it=mp.begin();it!=mp.end();it++)
        {
            if( it->second > 1 )
                ans/= fact[it->second];
        }

        printf("Data set %d: %llu\n", t, ans);

    }
}
