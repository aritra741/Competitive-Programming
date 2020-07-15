#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int len;
        cin>>len;
        string s;
        cin>>s;
        bool f=0;

        int mid=  ceil((double)len/2.0);

        for(int i=0;i<mid;i++)
        {
            if( abs(s[i]-s[len-i-1])>2 or abs(s[i]-s[len-i-1])==1)
            {
                f=1;
                break;
            }
        }

        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
