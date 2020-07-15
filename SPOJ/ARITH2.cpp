#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    getchar();

    while(tc--)
    {
        getchar();

        string s;

        getline( cin, s );

        string t="";
        stringstream ss1;
        ss1<<s;
        bool num=1;
        bool first=1;
        bool add=0, sub=0, mult=0, dvd=0;
        bool neg=0;
        ll ans=0;

        while( getline(ss1, t, ' ' ) )
            {
                if(t=="=")
                   break;
                stringstream ss;
                ss<<t;

             //   cout<<ans<<endl;

                if( num )
                {
                    if(t=="-")
                        {
                            neg=1;
                            continue;
                        }
                    num=0;
                    ll p;
                    ss>>p;

                    if(neg)
                        neg=0, p=-p;

                    if(first)
                        {
                            ans=p;
                            first=0;

                        }

                    else
                    {
                        if( add )
                        {
                            ans+=p;
                            add=0;
                        }

                        else if( sub )
                        {
                            ans-=p;
                            sub=0;
                        }

                        else if( mult )
                        {
                            ans*=p;
                            mult=0;
                        }

                        else if( dvd )
                        {
                            ans/=p;
                            mult=0;
                        }
                    }
                }

                else
                {
                    num=1;
                    if( t=="+" )
                        add=1;
                    else if( t== "-")
                        sub=1;
                    else if( t=="*" )
                        mult=1;
                    else
                        dvd=1;
                }
            }

            cout<< ans <<endl;
}
}
