#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;

    int len1= s.size();
    int len2= t.size();

    int one[len2+5],zero[len2+5];

    zero[0]=one[0]=0;

    for(int i=0;i<len2;i++)
        {
            one[i+1]=one[i]+(t[i]-'0');
            zero[i+1]=zero[i]+!(t[i]-'0');
        }


    long long ans=0;

    for(int i=1;i<=len1;i++)
    {
        if(s[i-1]=='0')
            ans+=one[len2-len1+i]-one[i-1];
        else
            ans+=zero[len2-len1+i]-zero[i-1];
    }

    cout<<ans<<endl;

}
