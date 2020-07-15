#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define pii pair<int,int>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ost;
int k;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        k=0;
        ost arr;

        int cnt= 0;
        while(1)
        {
            int p;
            scanf("%d", &p);

            if(!p)
                break;
            if(p!=-1)
                cnt++, arr.insert( pii(p,k++) );

            else
            {
                pii q= (*arr.find_by_order( (cnt+1)/2-1 ));
                printf("%d\n", q.first);
                arr.erase( arr.lower_bound( q ) );
                cnt--;
            }
        }
    }
}
