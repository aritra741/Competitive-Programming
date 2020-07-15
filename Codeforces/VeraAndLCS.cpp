#include <bits/stdc++.h>
using namespace std;

int a[27];

int main()
{
    int n,k;
    cin>>n>>k;

    if(k>n)
    {
        cout<<"WRONGANSWER\n";
        return 0;
    }

    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
        a[s[i]-'a']++;

    int rem= n-k;

    for(int i=0;i<26;i++)
        if( !a[i] )
            while(rem)
                cout<< (char)(i+'a') ,
                rem--;

    if(rem and !k)
    {
        cout<<"WRONGANSWER\n";
        return 0;
    }

    for(int i=0;i<k;i++)
        cout<< s[i];
}
