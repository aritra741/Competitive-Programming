#include<bits/stdc++.h>
#define mx 1000007
using namespace std;

int ase[mx];
vector<int>arr(mx);
int n;
int br;

int main()
{
    scanf("%d", &n);

    for( int i=0; i<n; i++ )
        scanf("%d", &arr[i]), br= max( br, arr[i] );

    sort( arr.begin(), arr.begin()+n );
    auto it= unique( arr.begin(), arr.begin()+n );
    arr.resize( distance( arr.begin(), it ) );

    int ans= 0;
    n= arr.size();

    for( int i=0; i<arr.size(); i++ )
    {
        int x= arr[i];
        for( int j=2;; j++ )
        {
            int pos= lower_bound( arr.begin(), arr.end(), x*j )-arr.begin();
            pos--;

            if(pos>0)
                ans= max( ans, arr[pos]%x );

            if( x*j>br*10 )
                break;
            if( pos==n-1 )
                break;
        }
    }

    printf("%d\n", ans);
}
