#include <bits/stdc++.h>
using namespace std;

int arr[1000007];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>arr[i], arr[i]+=arr[i-1];

    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int p;
        cin>>p;

        int high= n, low= 1, mid;

        for(int j=0;j<100;j++)
        {
            mid= (high+low)/2;
            if( arr[mid]<p )
                low= mid;
            else
                high= mid;
        }

        cout<< high <<endl;
    }

}
