#include <bits/stdc++.h>
#define ull unsigned long long
#define pull pair<ull, int>
#define MAX 1000000000
using namespace std;

ull zero(long long n)
{

    long long i=5;
    ull ans=0;
    while(n>=i)
    {
        ans+=n/i;
        i*=5;
    }

    return ans;
}



int main()
{

    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        bool flag=0;
        int point=-1;
        ull target;
        scanf("%llu", &target);
        long long l=1,r=MAX;
        while(l<=r)
        {
            if(l==r)
            {
                if(zero(l)==target)
                {
                    flag=1;
                    point=l;
                }
                break;
            }
            int mid=l+(r-l)/2;
            if(zero(mid)==target)
            {
                flag=1;
                point=mid;
                break;
            }
            else if(zero(mid)<target)
                l=mid+1;
            else
                r=mid-1;
            //   cout<<l<<" "<<r<<endl;

        }
        if(flag==0)
            printf("Case %d: impossible\n",i);
        else if(point!=-1)
        {
            while(point>0)
            {
                if(zero(point-1)==target)
                    point--;
                else
                    break;
            }
            printf("Case %d: %d\n", i, point);
        }
    }
}
