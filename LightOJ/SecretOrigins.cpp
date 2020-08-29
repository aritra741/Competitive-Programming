#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
string tobin(ull n)
{
    stringstream ss;
    ss.str()="";
    string r;
    ull num;
    while(n!=0)
    {
        num=n%2;
        n=n/2;
        ss<<num;
    }
    ss>>r;
    int len=r.length();
    r[len]=0;
    reverse(r.begin(), r.end());
    return r;
}

ull todec(string s)
{
    ull dec=0;
    ull num=1;
    ull cnt=1;
    int len=s.length();
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='1')
            dec+=num;
        num=num<<1;
    }
    return dec;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
    {
        ull n;
        scanf("%llu", &n);
        string s=tobin(n);
        s.insert(s.begin()+0, 1, '0');
        next_permutation(s.begin(), s.end());
        ull ans=todec(s);
        printf("Case %d: %llu\n", i, ans);





    }
}
