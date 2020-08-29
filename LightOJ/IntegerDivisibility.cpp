#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull div(ull n, ull k)
{
    string s;
    stringstream ss;
    ss.str()="";
    ss<<k;
    ss>>s;
    ull rem=0;
    ull i=0;
    do{
            cout<<rem<<endl;
    rem=(rem*10+s[i]-'0')%n;
    s.insert(s.begin()+0,k);
    }while(rem!=0);
    return s.length()-1;
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        ull n,k;
        scanf("%llu %llu", &n,&k);
        ull ans=div(n,k);
        printf("Case %d: %llu\n", i, ans);
    }
}
