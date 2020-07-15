#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s;
    cin>>s;

    int cnt=0;

    while( s.size()!=1 )
    {
        cnt++;
        int len= s.size();
        ll tot=0;

        for(int i=0;i<len;i++)
        {
            tot+= (s[i]-'0');
        }

        stringstream ss;
        ss<<tot;
        ss>>s;
    }

    cout<<cnt<<endl;
}
