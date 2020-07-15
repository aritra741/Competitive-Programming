#include <bits/stdc++.h>
#define pii pair<int,int>
#define inf 1e9
using namespace std;

int arr[10007];
int I[10007];

int main()
{
    int i= 0;

    while( cin>>arr[i].second>>arr[i++].first );

    sort( arr, arr+i );

    for(int j=1;i<i;j++)
        I[j]= inf;
    I[0]= -inf;

    int ans= 1;
    for(int j=1;j<=i;j++)
    {
        it= lower_bound( I, I+i, arr[i].second );
        int pos= it-I;

        I[pos]= arr[i].second;
        L[i]= pos;

    }


}
