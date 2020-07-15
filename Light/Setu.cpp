#include <string.h>
#include <sstream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        printf("Case %d:\n", i);
        int n,sum=0;
        cin>>n;
        getchar();
        for(int j=0;j<n;j++)
        {
    stringstream ss;
    ss.str()="";
    string s;
    string t="";
    int num;
    getline(cin, s);
    if(s[0]=='d'){
    ss<<s;
    while(!ss.eof())
    {
        ss>>t;
        if(stringstream(t)>>num)
            sum+=num;
        t="";
    }
        }
        else
            cout<<sum<<endl;

    }

}
}
