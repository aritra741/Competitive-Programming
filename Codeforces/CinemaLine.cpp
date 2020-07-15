#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    bool flag=0;
    ll tw=0,fif=0,hun=0,sum=0;
    ll temp;
    for(int i=0;i<n;i++)
    {

        cin>>temp;
        //cout<<temp<<" "<<sum<<" ";
        if((temp!=25) && (temp-25>sum) )
            {
                flag=1;
                break;
            }
        if(temp==100)
        {
            if(fif>=1 && tw>=1)
               {
                   fif--;
                   tw--;
                   sum+=25;
               }
            else if(tw>=3)
                {
                    tw-=3;
                    sum+=25;
                }
            else
            {
                flag=1;
                break;
            }

        }
        else if(temp==50)
        {
            if(tw>=1)
                {
                    tw--;
                    fif++;
                    sum+=25;
                }
               // cout<<sum<<endl;
            else
            {
                flag=1;
                break;
            }
        }
        else
            {
                tw++;
                sum+=25;
                //cout<<sum<<endl;
            }

     }
    if(flag==1)
        cout<<"NO";
    else
        cout<<"YES";
}
