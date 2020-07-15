#include  <bits/stdc++.h>
using namespace std;

int st[150007];

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        int len= s.size();
        char mx=0;
        map <char, int> mp;

        for(int i=0; i<len; i++)
            mx= max( mx, s[i] ),
            mp[s[i]]++;

        int tot= len- mp[mx];
        int cnt=0;
        int step=1;

        while(tot)
        {
            bool flag=0;

            for(int i=0; i<len; i++)
            {
                if(!tot)
                    break;

                if(st[i]==step)
                        continue;
                if( i!=len-1 and s[i]==mx)
                {

                    for(int j=i+1; j<len; j++)
                    {
                        if( s[j]!=mx and s[i]- s[j] >= j-i )
                            s[j]=mx, st[j]=step, tot--, flag=1;
                    }

                }

                if(i and s[i]==mx)
                {
                    for(int j=i-1;j>=0;j--)
                    {
                        if( s[j]!=mx and s[i]- s[j] >= i-j )
                            s[j]=mx, st[j]=step, tot--, flag=1;
                    }
                }

            }

            if(flag)
                cnt++;

            step++;
            cout<<s<<endl;
        }

        cout<<cnt<<endl;
        memset( st, 0, sizeof(st) );

    }
}
