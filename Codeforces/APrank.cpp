#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if(n==1)
        {
            cout<<"0";
            return 0;
        }

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    if(n==2)
    {
        if( (arr[0]==1 and arr[1]==2) or (arr[0]==999 and arr[1]==1000) )
            cout<<"1";
        else
            cout<<"0";
        return 0;
    }

    int st= arr[0], en= arr[1], len= 0;
    int cnt= 0, ans= 0;

    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[i-1]==1)
        {
            if(len==0)
                len=2, st= arr[i-1];
            else
                len++;
        }

        else if( len )
        {
            en= arr[i-1];
            cnt+=(len-2);

            if(st==1 or en==1000)
                cnt++;

            len= 0;
            ans= max(ans,cnt);
            cnt= 0;
        }
    }

    if(len)
    {
        cnt+=(len-2);

        if(st==1 or arr[n-1]==1000)
            cnt++;

        ans= max(ans, cnt);
    }

    cout<<ans<<endl;
}
