#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        int a[n+2], d[n+2];

        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>d[i];

        a[0]= a[n], a[n+1]= a[1];
        d[0]= d[n], d[n+1]= d[1];
        vector<int> v;
        //cout<<"agey\n";
        for(int i=1;i<=n;i++)
        {
            int tot= a[ i-1 ]+a[ i+1 ];
            //cout<<i<<" "<<tot<<" "<<d[i]<<endl;
            if( tot<d[i] )
                v.push_back( d[i] );
        }
      //  cout<<"pore\n";
        sort( v.begin(),v.end() );

        if( v.size() )
            cout<< v[ v.size()-1 ] <<endl;
        else
            cout<<"-1\n";
    }
}
