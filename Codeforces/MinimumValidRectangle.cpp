#include <bits/stdc++.h>
using namespace std;

int mp[1000007];
vector <int> v;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        v.clear();

        int n;
        scanf("%d", &n);
        int mx=-1;

        for(int i=0;i<n;i++)
        {
            int p;
            scanf("%d", &p);
            if(mx<p)
                mx=p;
            mp[p]++;
            if(mp[p]>=2)
                {
                    v.push_back(p);
                    mp[p]-=2;
                }
        }

        sort(v.begin(), v.end());

        int sz=v.size(),x=-1,y=-1;
        double mn=1e18;

        for(int i=0;i<sz-1;i++)
            {
                if( 4.0*(double)(v[i]+v[i+1])*(v[i]+v[i+1])/(v[i]*v[i+1])<mn )
                {
                    mn=4.0*(v[i]+v[i+1])*(v[i]+v[i+1])/(v[i]*v[i+1]);
                    x=v[i],y=v[i+1];
                }
            }

       printf("%d %d %d %d\n", x,x,y,y);

       for(int i=0;i<=mx;i++)
            mp[i]=0;

    }
}
