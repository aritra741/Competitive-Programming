#include <bits/stdc++.h>
using namespace std;

bool arr[110];

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        memset(arr,0, sizeof(arr));

        int n;
        cin>>n;
        string s;
        cin>>s;

        int cnt=0;

        for(int i=1;i<n;i++)
        {
            if(s[i-1]=='.' and !arr[i-1] and !arr[i+1] and !arr[i])
                arr[i-1]=arr[i]=arr[i+1]=1,cnt++;
        }

        for(int i=0;i<n;i++)
            if(arr[i]==0 and s[i]=='.')
                cnt++;

        cout<<"Case "<<t<<": "<<cnt<<endl;
    }
}
