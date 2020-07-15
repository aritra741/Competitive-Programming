#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        string s,t;
        cin>>s;
        cin>>t;
        bool flag=0;
        stringstream ss,ss1;
        ss<<s;
        ss1<<t;
        string tempD="", tempB="";
        stringstream deci;
        stringstream tempo;
        while( getline(ss, tempD, '.') && getline(ss1, tempB, '.') )
        {
            tempo<<tempD;
            int dec;
            tempo>>dec;
            tempo=stringstream();
            int len=tempD.length();
            for(int j=0; j<=7; j++)
            {

                int temp=((dec>>j)&1);
                deci<<temp;

            }
            deci>>tempD;
            deci=stringstream();
            reverse(tempD.begin(), tempD.end());
            //cout<<tempB<<" "<<tempD<<endl;
            if(tempD!=tempB)
                   flag=1;

        }
        if(!flag)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }
}
