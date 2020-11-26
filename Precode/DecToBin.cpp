#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stringstream ss;
    ss<<s;
    int num;
    ss>>num;
    string t;
//    stringstream ss1;
//    ss1.str()="";
    ss=stringstream();
    for(int i=0;i<=7;i++)
    {

        int temp=((num>>i)&1);
        ss<<temp;

    }

    ss>>t;
    reverse(t.begin(), t.end());
    cout<<t;
    }
