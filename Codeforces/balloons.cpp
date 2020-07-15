#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

pii arr[20];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second= i+1;
    }

    if(n==1)
    {
        cout<<"-1";
        return 0;
    }

    if(n==2)
    {
        if( arr[0].first==arr[1].first )
            {
                cout<<"-1";
                return 0;
            }

    }

    sort(arr, arr+n);

    cout<<"1\n";
    cout<<arr[0].second;
}
