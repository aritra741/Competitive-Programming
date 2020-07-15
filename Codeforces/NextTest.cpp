#include <bits/stdc++.h>
using namespace std;

int arr[3010];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int p;
        cin>>p;

        arr[p]= 1;
    }

    for(int i=1; i<=3010; i++)
    {
        if( !arr[i] )
        {
            cout<< i <<endl;
            return 0;
        }
    }
}
