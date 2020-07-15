#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    string s1= s,t1= t;

    int cnt= 0, len= s.size();

    for(int i=0;i<len;i++)
    {
        if(!i)
        {
            if(s[i]=='0' and t[i]=='0' and t[i+1]=='0' )
                cnt++, s[i]= 1, t[i]=1 ,t[i+1]=1;
        }

        else if( i==len-1 )
        {
            if(s[i]=='0' and t[i]=='0' and t[i-1]=='0')
                cnt++, s[i]= 1, t[i]= 1, t[i-1]= 1;
        }

        else
        {
            if( s[i]=='0' and t[i]=='0')
            {
                if(t[i-1]=='0')
                    cnt++, t[i-1]= 1;
                else if( t[i+1]=='0' )
                    cnt++, t[i+1]= 1;
            }
        }
    }

    int cnt1= 0;

    for(int i=0;i<len;i++)
    {
        if(!i)
        {
            if(s1[i]=='0' and t1[i]=='0' and t1[i+1]=='0' )
                cnt1++, s1[i]= 1, t1[i]=1 ,t1[i+1]=1;
        }

        else if( i==len-1 )
        {
            if(s1[i]=='0' and t1[i]=='0' and t1[i-1]=='0')
                cnt1++, s1[i]= 1, t1[i]= 1, t1[i-1]= 1;
        }

        else
        {
            if( s1[i]=='0' and t1[i]=='0')
            {
                if(t1[i-1]=='0')
                    cnt1++, t1[i-1]= 1;
                else if( t1[i+1]=='0' )
                    cnt1++, t1[i+1]= 1;
            }
        }
    }

    cout<< max(cnt, cnt1) <<endl;
}
