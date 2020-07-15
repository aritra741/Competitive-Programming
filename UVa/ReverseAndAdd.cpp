#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int c=0,sum;
        string s1,s2;
        cin>>s1>>s2;
        string s="";
        if(s1.length()>s2.length())
            swap(s1,s2);
        int len1=s1.length();
        int len2=s2.length();
        for(int i=0; i<len1; i++ )
        {
            sum=(s1[i]-'0')+(s2[i]-'0')+c;
            s.push_back( sum%10+'0' );
            c=sum/10;

        }
        for(int i=len1; i<len2; i++)
        {
            sum=(s2[i]-'0')+c;
            s.push_back( sum%10 +'0');
            c=sum/10;

        }
        if(c)
            s.push_back(c+'0');
        s.erase(0, min(s.find_first_not_of('0'), s.size()-1));

        cout<<s<<endl;

    }


}


