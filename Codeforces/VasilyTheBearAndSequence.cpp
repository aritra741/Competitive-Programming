#include <bits/stdc++.h>
using namespace std;

int arr[100007];

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    for( int i=31;i>=0;i-- )
    {
        vector <int> v;

        for( int j=0;j<n;j++ )
            if( (arr[j]>>i)&1 )
                v.push_back( arr[j] );

        int And= (1<<i)-1;
        for( int j=0;j<v.size();j++ )
            And&= v[j];

        if( And%(1<<i)==0 )
        {
            cout<< v.size() <<endl;
            for( int j=0;j<v.size();j++ )
                cout<< v[j] <<" ";
            return 0;
        }
    }
}
