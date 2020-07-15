#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
map<int,int> ::iterator it;

int main()
{
    int n,k;
    string s;
    cin>>n>>k;

    for(int i=0;i<=n;i++)
    {
        cin>>s;
        mp[s.size()]++;
    }
    mp[s.size()]--;
    int fewer= 0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        if( (it->first)>=s.size() )
            break;
        fewer+= it->second;
    }

    int penalty= fewer/k;
    int best= fewer+penalty*5;
    best++;

    int same= mp[s.size()]-1;
    int worst= fewer+same;
    worst+=(worst/k)*5;
    worst++;

    cout<<best<<" "<<worst<<endl;
}
