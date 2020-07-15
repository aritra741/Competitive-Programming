#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100];
    int prime[25];
    int j=0;
    memset(arr, 0, sizeof(arr));
    for(int i=2; i<=97; i++)
        if(arr[i]==0)
        {
            prime[j++]=i;
            for(int p=1; p*i<=100; p++)
                arr[p*i]=1;
        }

    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        int n;
        cin>>n;
        int j=0;
        printf("Case %d: %d = ",i,n);
        while(prime[j]<=n && j<25)
        {
            int temp=prime[j];
            printf("%d ", prime[j]);
            int cnt=0;
            while(temp<=n && temp!=0)
            {

                cnt+=n/temp;
                temp*=prime[j];
            }
            printf("(%d)", cnt);
            if(prime[j+1]<=n && j+1<=24)
            {
                printf(" * ");
                j++;
            }
            else
            {
                printf("\n");
                break;
            }

        }
    }

}
