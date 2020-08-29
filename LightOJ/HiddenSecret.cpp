#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
getchar();
    for(int i=1;i<=tc;i++)
    {

        string s,s1;
        getline(cin,s);
        getline(cin,s1);
         transform(s.begin(),s.end(),s.begin(), ::tolower);
        transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
        stringstream ss,ss1;
        ss<<s;
        ss1<<s1;
        string t="";
        string t1="";
        string n1="",n2="";
        while(getline(ss,t,' '))n1+=t;
        while(getline(ss1,t1,' '))n2+=t1;
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());

        if(n1==n2)
            cout<<"Case "<<i<<": "<<"Yes"<<endl;
        else
            cout<<"Case "<<i<<": "<<"No"<<endl;
    }
}
