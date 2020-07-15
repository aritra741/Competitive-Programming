#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    for(int i=0;i<n;i++)
        arr[ s[i]-'a' ]++;

    bool flag=0;

    for(int i=0;i<26;i++)
        if(arr[i]>=2)
            flag=1;

    if(flag or n==1)
    cout<<"Yes";

    else
        cout<<"No";

}
