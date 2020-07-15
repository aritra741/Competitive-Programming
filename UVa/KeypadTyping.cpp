#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main()
{
    mp['a']=1;
    mp['b']=2;
    mp['c']=3;
    mp['d']=1;
    mp['e']=2;
    mp['f']=3;
    mp['g']=1;
    mp['h']=2;
    mp['i']=3;
    mp['j']=1;
    mp['k']=2;
    mp['l']=3;
    mp['m']=1;
    mp['n']=2;
    mp['o']=3;
    mp['p']=1;
    mp['q']=2;
    mp['r']=3;
    mp['s']=4;
    mp['t']=1;
    mp['u']=2;
    mp['v']=3;
    mp['w']=1;
    mp['x']=2;
    mp['y']=3;
    mp['z']=4;
    mp[' ']=1;
    int tc;
    cin>>tc;
    getchar();
    for(int i=1;i<=tc;i++)
    {

        string s;
        getline(cin, s);
        int len=s.length();
        int sum=0;
        for(int j=0;j<len;j++)
            sum+=mp[s[j]];

        cout<<"Case #"<<i<<": "<<sum<<endl;
    }
}
