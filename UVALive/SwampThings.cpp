#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

struct pt
{
    int x,y;
};

vector<pt>v;

int main()
{
    int t= 1;

    while(1)
    {
        int n;
        scanf("%d", &n);

        if(!n)
            break;

        for( int i=0; i<n; i++ )
        {
            pt p;
            scanf("%d %d", &p.x, &p.y);

            v.push_back(p);
        }

        map<pii,int>mp;

        int ans= 0;

        for( int i=0; i<n; i++ )
        {
            mp.clear();
            for( int j=i+1; j<n; j++ )
            {
                int nich= v[i].x-v[j].x;
                int upor= v[i].y-v[j].y;

                int g= __gcd( nich,upor );

                nich/= g;
                upor/= g;

                mp[pii(upor,nich)]++;

                ans= max( ans, mp[pii(upor,nich)] );
            }
        }

        printf("Photo %d: ", t++);

        if(ans+1<4)
            ans= -1;

        printf("%d points eliminated\n", ans+1);

        v.clear();
    }
}
