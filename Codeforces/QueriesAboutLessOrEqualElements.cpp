#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> ::iterator it;

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        int p;
        cin>>p;
        v.push_back(p);
    }

    int idx= 0;
    int arr[m];

    for(int i=0; i<m; i++)
        cin>>arr[i];

    sort(arr,arr+m);

    for(int i=0; i<m; i++)
    {
        for(; idx<n; idx++)
        {
            if(v[idx]>arr[i])
                break;
        }
        cout<< idx <<" "<<endl;
    }

}
