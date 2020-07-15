#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int j= 0;
    for(int i=0;j+i<s.size();i++)
    {
        cout<<s[j+i];
        j+=i;
    }
}
