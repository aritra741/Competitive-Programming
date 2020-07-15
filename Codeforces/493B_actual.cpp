#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>v1,v2;

int main()
{
    int n;
    cin>>n;

    ll sum1= 0, sum2= 0;
    ll p;

    for( int i=0;i<n;i++ )
    {
        cin>>p;

        if(p<0)
            sum1+= p, v1.push_back(p);
        else
            sum2+= -p, v2.push_back(-p);
    }

    if( sum1>sum2 )
        cout<<"first\n";
    else if( sum1<sum2 )
        cout<<"second\n";
    else
    {
        int f= 0;

        for( int i=0;i<min( v1.size(), v2.size() );i++ )
        {
            if( v1[i]>v2[i] )
            {
                f= 1;
                break;
            }
            else if( v1[i]<v2[i] )
            {
                f= 2;
                break;
            }
        }

        if(f==1)
            cout<<"first\n";
        else if(f==2)
            cout<<"second\n";
        else if(p>0)
            cout<<"first\n";
        else
            cout<<"second\n";
    }

}
