#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        getchar();
        int n;
        cin>>n;

        ll arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        double ex[n];
        ex[n-1]=arr[n-1];

        for(int i=n-2;i>=0;i--)
        {
            int it=min(i+6, n-1);
            int diff=it-i;
            double temp=0;
            for(int j=1;j<=diff;j++)
                temp+=(ex[i+j]+arr[i]);
            temp/=diff;
            ex[i]=temp;
        }

        cout<<"Case "<<t<<": "<<setprecision(10)<<fixed<<ex[0]<<endl;
    }
}
