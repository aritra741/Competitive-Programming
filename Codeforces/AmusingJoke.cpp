#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1;
    cin>>s;
    cin>>s1;
    string ss=s+s1;
    sort(ss.begin(), ss.end());
    string s3;
    cin>>s3;
    sort(s3.begin(), s3.end());
    if(s3==ss)
        cout<<"YES";
    else
        cout<<"NO";
}
