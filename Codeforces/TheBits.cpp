#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    int no_of_1s=0, no_of_0s=0;

    for(long long i=0;i<n;i++)
    {
        if(s[i]-'0')
            no_of_1s++;
        else
            no_of_0s++;
    }

    if(!no_of_1s or !no_of_0s)
    {
        cout<<"0"<<endl;
        return 0;
    }

    long long ans=0;

    for(long long i=0;i<n;i++)
    {
        if( !(t[i]-'0') )
            {
                if( s[i]-'0'==1 )
                    {
                        ans+= no_of_0s;
                        no_of_1s--;
                    }
                else
                {
                    ans+= no_of_1s;
                    no_of_0s--;
                }
            }
    }

    cout<<ans<<endl;


}
