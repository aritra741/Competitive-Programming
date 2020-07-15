#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    int n,b;
    cin>>n>>b;

    int arr[n];
    int odd=0, even=0;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n-1;i++)
    {
        if( arr[i]&1 )
            odd++;
        else
            even++;

        if(odd==even)
        {
            int temp= abs(arr[i+1]-arr[i]);
            v.push_back(temp);
            odd=0, even=0;
        }
    }

    sort(v.begin(), v.end());
    int tot=0,cnt=0;

    for(int i=0;i<v.size();i++)
    {
        if( tot+v[i]<=b )
            tot+=v[i], cnt++;
    }

    cout<< cnt <<endl;

}
