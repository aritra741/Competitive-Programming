#include <bits/stdc++.h>
using namespace std;
int main()
{

    while(1)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if( !(a+b+c) )
            break;
        int arr[20000];
        memset(arr, 0, sizeof(arr));
        for(int j=2; a*j<=19000; j+=2)
        {
            for(int k=0; k<a-5; k++)
                arr[a*j+k]++;
        }
        for(int j=2; b*j<=19000; j+=2)
        {
            for(int k=0; k<b-5; k++)
                arr[b*j+k]++;
        }
        int cnt=2;
        while(c)
        {
            cnt++;
            for(int j=2; c*j<=19000; j+=2)
            {
                for(int k=0; k<c-5; k++)
                    arr[c*j+k]++;
            }

            cin>>c;
        }

        int ans=0;
        for(int i=1;i<20000;i++)
            if(arr[i]==cnt)
                {
                    ans=i;
                    break;
                }

        if(ans>18000 or !ans)
        {
            cout<<"Signals fail to synchronise in 5 hours"<<endl;
            continue;
        }

        //cout<<ans<<endl;
        int hour= ans/3600;
        int minute= (ans%3600)/60;
        int sec= ans%60;

        printf("%02d:%02d:%02d\n", hour, minute, sec);

    }
}
