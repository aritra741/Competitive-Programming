#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int flag=0;
    int start=1,fin=1;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            if(flag==2)
            {
                flag=3;
                break;
            }

            if(!flag)
            {
                start=i+1;
                flag=1;
            }

        }

        else if(arr[i]<arr[i+1] and flag==1)
        {
            fin=i+1;
            flag=2;
        }
    }

    if(flag==3)
        cout<<"no"<<endl;
    else
    {
        if(flag==1)
            fin=n;
        reverse(arr+start-1, arr+fin);
        if(is_sorted(arr, arr+n))
        {
            cout<<"yes"<<endl;
            cout<<start<<" "<<fin<<endl;
        }

        else
            cout<<"no"<<endl;
    }
}
