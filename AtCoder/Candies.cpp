#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n,k;
int arr[107];
ll dp[107][100007];

int rec( int i, int x )
{
    if( x>k )
        return 0;

    if( i>n )
    {
        if(x==k)
            return 1;
        return 0;
    }
    int ret= 0;

    for( int j=0; j<=arr[i]; j++ )
        ret= ( ret+rec( i+1, x+j ) )%mod;

    return ret;
}

int main()
{
    cin>>n>>k;

    for( int i=1; i<=n; i++ )
        cin>>arr[i];

    vector<ll>sum;
    for( int i=0; i<k; i++ )
        sum.push_back(0);
    sum.push_back(1);


    for( int peep=n; peep>=1; peep-- )
    {
        vector<ll>now;

        for( int total=0; total<=k; total++ )
        {
            if(total)
                dp[peep][total]= (sum[ min(k,total+arr[peep]) ]-sum[total-1]+mod)%mod;
            else
                dp[peep][total]= sum[ min(k,total+arr[peep]) ];

            if(total)
                now.push_back( (now.back()+dp[peep][total])%mod );
            else
                now.push_back( dp[peep][total] );

//            cout<<peep<<" "<<total<<" "<< dp[peep][total] <<" "<<rec( peep, total ) <<endl;
        }

        sum.swap(now);
    }

    cout<< dp[1][0] <<endl;
}
