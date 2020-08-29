#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define pdd pair< double, double >
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        vector <pll> mid;

        int n;
        cin>>n;
        if(n<=3)
        {
            printf("Case %d: 0\n", i);
            continue;
        }
        vector <pll> points;
        for(int j=0;j<n;j++)
        {
            long long x,y;
            scanf("%lld %lld", &x, &y);
            points.push_back( pll(x,y) );

        }
        for(int j=0;j<n;j++)
            for(int p=0;p<j;p++)
                {
                        int px= (points[j].first+ points[p].first);
                        int py= (points[j].second+ points[p].second);
                        //cout<<px<<" "<<py<<endl;
                        mid.push_back( pll(px,py));
                }
        unsigned long long ans=0;
        sort(mid.begin(), mid.end());
        int sz=mid.size();
        int cnt=1;
        pll curr;
        curr.first=1000000001;
        curr.second=1000000001;
        for(int j=1;j<sz;j++)
        {
            //cout<<mid[j].first<<" "<<mid[j].second<<" "<<curr.first<<" "<<curr.second<<endl;
            if( mid[j].first==curr.first && mid[j].second==curr.second )
                cnt++;
            else{
                   // cout<<cnt<<endl;
                curr=mid[j];
                ans+=(cnt-1)*cnt;
                cnt=1;
            }
        }
        ans/=2;
        printf("Case %d: %d\n", i, ans);


    }
}
