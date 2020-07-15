#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        int mn= 1e9;

        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;

            int a=0,b=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='a')
                    a++;
                else if(s[j]=='b')
                    b++;
            }

            mn= min( mn, min(a,b) );
        }

        cout<< mn <<endl;
    }
}
