#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
map<int, int> ::iterator it;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[ arr[i] ]++;
    }

    int cnt=0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        if( it->second==1 )
            cnt++;
    }

    if((cnt & 1))
    {
        cout<<"NO"<<endl;
        return 0;
    }

    else if(cnt==0)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<"A";
    }

    else
    {
        cout<<"YES"<<endl;

        int num= cnt/2;
        int now=0;

        int i;

        for(i=0;i<n;i++)
        {

            if(now==num)
                break;

            if( mp[ arr[i] ]>1 )
                cout<<"B";
            else if( mp[ arr[i] ]==1 )
            {
                cout<<"B";
                now++;
            }
        }

        now=0;

        for(;i<n;i++)
        {
            if( mp[ arr[i] ]>1 )
                cout<<"B";
            else if( mp[ arr[i] ]==1 )
            {
                cout<<"A";
            }
        }
    }

}
