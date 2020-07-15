#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    double arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort( arr, arr+n, greater<double>() );

    double a= arr[0];

    for(int i=1;i<n;i++)
        a= 2.0*sqrt(arr[i]*a);

    cout<<setprecision(2)<<fixed<<a<<endl;
}
