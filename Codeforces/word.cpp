#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cap=0,sml=0;
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(islower(s[i]))
            sml++;
        else
            cap++;
    }
    if(sml>=cap)
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    else
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s;
}

