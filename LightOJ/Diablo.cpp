#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++)
    {
        int n,q;

        printf("Case %d:\n", t);
        scanf("%d %d", &n, &q);

        vector<int> v;

        for(int i=0; i<n; i++)
        {
            int o;
            scanf("%d", &o);
            v.push_back(o);
        }

        while(q--)
        {
            char c[3];
            int p;

            scanf("%s", &c);

            if(c[0]=='a')
            {
                scanf("%d", &p);
                v.push_back(p);
            }

            else
            {
                scanf("%d", &p);

                if(p>v.size())
                    printf("none\n");

                else
                {
                    int u= v[p-1];
                    v.erase( v.begin()+p-1 );
                    printf("%d\n", u);
                }
            }
        }
    }
}
