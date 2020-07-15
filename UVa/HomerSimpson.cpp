#include <bits/stdc++.h>
#define inf 1e7
using namespace std;

int dp[10007];
int arr[3];
int target;
int mx= -1, idx= 0;



int main()
{
    while(cin>>arr[0]>>arr[1]>>target)
    {
        dp[0]= 0;

        for(int i=1;i<=target;i++)
        {
            int q1= -inf, q2= -inf;
            if(i>=arr[0])
                q1= dp[i-arr[0]]+1;
            if(i>=arr[1])
                q2=dp[i-arr[1]]+1;
            dp[i]= max(q1,q2);
        }

        for(int i=target;i>=0;i--)
        {
            if( dp[i]>=0 )
            {
                cout<< dp[i];

                if( target-i )
                    cout<<" "<<target-i;
                cout<<endl;
                break;
            }
        }
    }
}
