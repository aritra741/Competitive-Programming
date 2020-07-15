#include <bits/stdc++.h>
using namespace std;
//long long comb(int n, int r)
//{
//    long long ans=1;
//    r=(r>n/2)? (n-r) : r;
//    for(int i=1;i<=r;i++)
//    {
//        ans*=n-r+i;
//        ans/=i;
//    }
//    return ans;
//
//}
double fact[91];
int main()
{

    fact[0]=1;
    for(int i=1;i<=90;i++)
            fact[i]=i*fact[i-1];
    int tc;
    cin>>tc;
    for(int j=1;j<=tc;j++)
    {
        int n,k;
        scanf("%d %d", &n,&k);
//        if(k==1)
//            printf("Case %d: %d\n", j, n*n);
        if(k>n )
                printf("Case %d: 0\n", j);
        else if(k==0)
            printf("Case %d: 1\n", j);
        else
        {
//            long long grndtot=comb(n*n, k);
//            long long ans=comb(n, k)*n*2;
//            long long sub=ans;
//            int i=1;
//            while(n-i>=3)
//            {
//                sub+=comb(n, k-i)*n*2*comb((n-1)*(n-1), n-k);
//                i++;
//            }
////            cout<<ans<<endl;
//    printf("Case %d: %lld\n", j, grndtot-sub);

            cout<<(fact[k]+fact[n-k])*n*n<<endl;
        }

    }

}
