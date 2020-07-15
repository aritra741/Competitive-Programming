#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    int n;
    stringstream ss;
    cin>>n;
    n++;
    while(1)
    {
    ss.str("");
    ss<<n;
    string s;
    s=ss.str();

        if(s[0]==s[1] || s[0]==s[2] || s[0]==s[3] || s[1]==s[2] || s[1]==s[3] || s[2]==s[3])
                n++;
        else {
                cout<<s;
                break;
        }

    }

}
