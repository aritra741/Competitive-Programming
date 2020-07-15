#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int op=0;

    if(n==k)
        cout<<s;
    else
    {
        int cnt=0, half=k/2, open=0;
        for(int i=0; i<n; i++)
        {
            if(cnt==k)
                break;
            if(s[i]==')')
            {
                if(op>0)
                {
                    cout<<s[i];
                    op--;
                    cnt++;
                }
            }
            else
            {
                if(open<half)
                {
                    cout<<s[i];
                    op++;
                    open++;
                    cnt++;
                }
            }
        }
    }

}
