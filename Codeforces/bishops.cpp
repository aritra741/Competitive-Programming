#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int b=0,w=0;
        long long r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        if(c1%2==0)
        {
            if(r1%2==0)
            {
                w++;
            }
            else
                b++;
        }
        else if(c1%2!=0)
        {
            if(r1%2!=0)
                w++;
            else
                b++;
        }
        if(c2%2==0)
        {
            if(r2%2==0)
            {
                w++;
            }
            else
                b++;
        }
        else if(c2%2!=0)
        {
            if(r2%2!=0)
                w++;
            else
                b++;
        }


        if(w==1 &&  b==1)
        {
            cout<<"Case "<<i<<": impossible"<<endl;
        }
        else if(w==2 || b==2)
        {
            if((r1-c1)==(r2-c2) || (r1+c1)==(r2+c2))
                cout<<"Case "<<i<<": 1"<<endl;
            else
                cout<<"Case "<<i<<": 2"<<endl;
        }
    }
}
