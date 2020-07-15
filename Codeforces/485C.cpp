#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll l,r;
        cin>>l>>r;

        while(1)
        {
            bool f= 0;

            for( ll i=0;i<=63-__builtin_clzll(r);i++ )
            {
                if( !(l&(1LL<<i)) )
                {
                    if( (l|(1LL<<i)) > r )
                        break;
                    else
                    {
                        l|= (1LL<<i);
                        f= 1;
                        break;
                    }
                }
            }

            if(!f)
                break;
        }

        cout<<l<<endl;
    }
}
