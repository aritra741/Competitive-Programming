#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        int low=0,up=0,num=0;

        int len= s.size();

        for(int i=0; i<len; i++)
        {
            if( s[i]>='a' and s[i]<='z' )
                low++;
            else if( s[i]>='A' and s[i]<='Z' )
                up++;
            else
                num++;
        }

        int l=0,u=0,n=0;
        if(low)
            l=1;
        if(up)
            u=1;
        if(num)
            n=1;

        int dif= 3-(l+u+n);

        // cout<<dif<<endl;

        if( dif==0 )
            cout<<s<<endl;
        else if( dif==1 )
        {
            if( !low )
            {
                if(s[0]>='A' and s[0]<='Z')
                {
                    if(up>1)
                        s[0]='a';
                    else
                        s[1]='a';
                }
                if(s[0]>='0' and s[0]<='9')
                {
                    if(num>1)
                        s[0]='a';
                    else
                        s[1]='a';
                }

            }
            else if(!up)
            {
                if(s[0]>='a' and s[0]<='z')
                {
                    if(low>1)
                        s[0]='A';
                    else
                        s[1]='A';
                }
                if(s[0]>='0' and s[0]<='9')
                {
                    if(num>1)
                        s[0]='A';
                    else
                        s[1]='A';
                }
            }
            else
            {
                if(s[0]>='A' and s[0]<='Z')
                {
                    if(up>1)
                        s[0]='1';
                    else
                        s[1]='1';
                }
                if(s[0]>='a' and s[0]<='z')
                {
                    if(low>1)
                        s[0]='1';
                    else
                        s[1]='1';
                }

            }

            cout<<s<<endl;
        }

        else
        {
            if( !low and !up)
            {
                s[0]='a';
                s[1]='A';
            }

            else if( !low and !num )
            {
                s[0]='a';
                s[1]='1';
            }

            else
            {
                s[0]='A';
                s[1]='1';
            }

            cout<<s<<endl;
        }
    }
}
