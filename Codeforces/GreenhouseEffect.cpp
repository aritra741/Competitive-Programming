#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[n];
    int L[n];

    for(int i=0;i<n;i++)
    {
        double dummy;
        cin>>arr[i]>>dummy;
    }

    for(int i=0;i<n;i++)
        L[i]= 1;

    int Ans= 1;

    for(int i=0;i<n;i++)
    {
        int p= arr[i];
        for(int j=i+1;j<n;j++)
        {
            int q= arr[j];
            if( q>=p )
                L[j]= max( L[j], L[i]+1 ), Ans= max( Ans, L[j] );

        }
    }

    cout<< n- Ans <<endl;
}
