#include<bits/stdc++.h>
using namespace std;

int arr[25][25];

int main()
{
    int n;
    cin>>n;

    map<int,int>mp;
    int x;

    for( int i=0; i<n*n; i++ )
        cin>>x, mp[x]++;

    int cnt4= 0, cnt2= 0, cntb= 0;
    for( auto x: mp )
    {
        if( x.second%4==0 )
            cnt4++;
        else if( x.second%2==0 )
            cnt2++;
        else
            cntb++;
    }

    if( n%2==0 and (cnt2 or cntb) )
        return cout<<"NO\n", 0;
    if( n&1 and !cntb )
        return cout<<"NO\n", 0;

    if(n%2==0)
    {
        cout<<"YES\n";

        for( int i=0; i<n/2; i++ )
        {
            for( int j=0; j<n/2; j++ )
            {
                int v;
                auto it= *(mp.begin());
                v= it.first;

                mp[v]-= 4;

                if(!mp[v])
                    mp.erase(v);

                arr[i][j]= arr[i][n-j-1]= arr[n-i-1][j]= arr[n-i-1][n-j-1]= v;
            }
        }

        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
                cout<< arr[i][j] <<" ";
            cout<<endl;
        }
    }
    else
    {
        for( int i=0; i<n/2; i++ )
        {
            for( int j=0; j<n/2; j++ )
            {
                int v= -1;
                for( auto x: mp )
                {
                    auto it= x;
                    if( it.second>=4 )
                    {
                        v= it.first;
                        break;
                    }
                }

                if( v==-1 )
                    return cout<<"NO\n", 0;

                mp[v]-= 4;

                if(!mp[v])
                    mp.erase(v);

                arr[i][j]= arr[i][n-j-1]= arr[n-i-1][j]= arr[n-i-1][n-j-1]= v;
            }
        }

        for( int i=0; i<n/2; i++ )
        {
            if( mp.empty() )
                return cout<<"NO\n", 0;

            int v= -1;

            for( auto x: mp )
            {
                auto it= x;
                if( it.second>=2 )
                {
                    v= it.first;
                    break;
                }
            }

            if( v==-1 )
                return cout<<"NO\n", 0;

            mp[v]-= 2;

            if( !mp[v] )
                mp.erase(v);

            arr[i][n/2]= arr[n-i-1][n/2]= v;
        }

        for( int i=0; i<n/2; i++ )
        {
            if( mp.empty() )
                return cout<<"NO\n", 0;

            int v= -1;
            for( auto x: mp )
            {
                auto it= x;
                if( it.second>=2 )
                {
                    v= it.first;
                    break;
                }
            }

            if( v==-1 )
                return cout<<"NO\n", 0;


            mp[v]-= 2;

            if( !mp[v] )
                mp.erase(v);

            arr[n/2][i]= arr[n/2][n-i-1]= v;
        }

        if( mp.empty() )
            return cout<<"NO\n", 0;

        auto it= *(mp.begin());
        int v= it.first;
        arr[n/2][n/2]= v;

        cout<<"YES\n";
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
                cout<< arr[i][j] <<" ";
            cout<<endl;
        }
    }
}
