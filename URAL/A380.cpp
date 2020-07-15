#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stringstream ss;
    ss<<s;
    string t="";
    int num;
    ss>>num;
    if(num<3)
    {
        if(s[s.length()-1]=='B' || s[s.length()-1]=='C')
            cout<<"aisle";
        else
            cout<<"window";
    }
    else if(num<21)
    {
        if(s[s.length()-1]=='A' || s[s.length()-1]=='F')
            cout<<"window";
        else
            cout<<"aisle";
    }
    else
    {
        if(s[s.length()-1]=='A' || s[s.length()-1]=='K')
            cout<<"window";
        else if(s[s.length()-1]=='C' || s[s.length()-1]=='D' || s[s.length()-1]=='G' || s[s.length()-1]=='H')
            cout<<"aisle";
        else
            cout<<"neither";
    }
}
