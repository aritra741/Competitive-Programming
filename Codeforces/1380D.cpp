#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200009
#define mod 1000000007
ll t,n,m,i,j,k,l,arr[sz],brr[sz],crr[sz],drr[sz],x,y,a,b,ans,x1,y1,z1,x2,y2,z2;
vector<ll>v;
int main()
{
    scanf("%lld %lld %lld %lld %lld",&n,&m,&x,&k,&y);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        brr[arr[i]]=i;
    }
    for(i=1; i<=m; i++)
    {
        scanf("%lld",&crr[i]);
        drr[crr[i]]=i;
    }
    l=0;
    v.push_back(0);
    for(i=1; i<=m; i++)
    {
        a=brr[crr[i]];
        if(a<=l)
        {
            printf("-1\n");
            return 0;
        }
        l=a;
        v.push_back(l);
    }
    v.push_back(n+1);
   // printf("%d\n",v.size());
    for(i=0; i<v.size()-1; i++)
    {
        a=v[i];
        b=v[i+1];
        l=b-a-1;
        x1=l/k;
        x2=l%k;
        y1=0;
        y2=max(arr[a],arr[b]);
        for(j=a+1; j<b; j++)
            y1=max(y1,arr[j]);
        if(x1==0 && y1>y2)
        {
            printf("-1\n");
            return 0;
        }
        if(x<=y*k)
        {
            z1=x1*x;
            z2=x2*y;
            ans+=z1+z2;
        }
        else
        {
            if(y1<y2)
                ans+=(l*y);
            else
            {
                ans+=x;
                z1=(((x1-1)*k)+x2)*y;
                ans+=z1;
            }
        }
       // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}

