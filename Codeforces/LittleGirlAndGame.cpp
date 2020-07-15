#include <bits/stdc++.h>
using namespace std;

int cnt[27];

int main()
{
    string s;
    cin>>s;
    int len=s.size();

    for(int i=0;i<len;i++)
        cnt[ s[i]-'a'+1 ]++;

    int odd=0,even=0;

    for(int i=1;i<=26;i++)
        (cnt[i] & 1)? odd++ : even++;

    if( (odd & 1) or !odd )
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}
