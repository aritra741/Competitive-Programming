#include <bits/stdc++.h>
using namespace std;
int main()
{
    string ch=" ,.?!()";

    int tc;
    cin>>tc;
    getchar();
    for(int i=1; i<=tc; i++)
    {

        cout<<"Case #"<<i<<":"<<endl;
        bool flag=0;
        string s;
        getline(cin,s);
        int len=s.length();

        for(int i=0; i<len; i++)
            s.erase( remove(s.begin(), s.end(), ch[i]), s.end());
        len=s.length();

        for(int q=0; q<len; q++)
        {
            if(s[q]!=s[len-1-q])
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            cout<<"No magic :("<<endl;
        else
            cout<<sqrt(len)<<endl;
    }
}
