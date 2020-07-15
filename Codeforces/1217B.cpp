#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,x;
        cin>>n>>x;

        int ans= 0;

        int a= 0,b= 0;
        int mx= 0;

        while(n--)
        {
            int p,q;
            cin>>p>>q;

            mx= max( mx, p );

            if( p-q>ans )
                a= p, b= q, ans= p-q;
            else if( p-q==ans and p>a )
                a= p, b= q;
        }

        if(x<=mx)
            cout<<"1\n";
        else if( !ans )
            cout<<"-1\n";
        else
        {
            int y= max(0,(x-mx-1)/ans);
            x-= y*ans;

            while(x>0)
            {
                y++;

                if( x>mx )
                    x-= a;
                else
                    x-= mx;
                if( x<=0 )
                    break;
                x+= b;
            }

            cout<<y<<"\n";
        }
    }
}
