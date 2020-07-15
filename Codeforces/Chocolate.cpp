#include <bits/stdc++.h>
using namespace std;

bool arr[100];
vector <int> v;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i])
                v.push_back(i+1);
        }

    if(!v.size())
        cout<<"0"<<endl;
    else if(v.size()==1)
        cout<<"1"<<endl;
    else
    {
        long long ans=1;
        int sz=v.size();
        for(int i=1;i<sz;i++)
            ans*= ( v[i] - v[i-1] ) ;
        cout<<ans<<endl;
    }

}
