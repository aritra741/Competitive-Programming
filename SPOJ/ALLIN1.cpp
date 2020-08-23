#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

//see the data type in ordered set/multiset... and change int if it need
//ordered multiset cannot erase any eliment
// you can use less, less_equal, greater and greater_equal(maybe) needs to be checked
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pii,null_type,less<pii>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int cnt;

int main(int argc, char const *argv[])
{
    int tp, n;
    map<int,int>mp;
    ordered_set X;
    int ase= 0;

    while(1)
    {
        scanf("%d", &tp);

        if(tp==-1)
            return 0;

        int p;
        scanf("%d", &p);

        if( tp==1 )
            X.insert(pii(p,cnt++)), mp[p]= 1, ase++;
        else if( tp==2 and mp[p] )
        {
            X.erase( X.lower_bound(pii(p,0)) );
            mp[p]--;
            ase--;

            if(!mp[p])
                mp.erase(p);
        }
        else if( tp==3 )
        {
            if( mp.find(p)==mp.end() )
                printf("-1\n");
            else
                printf("%d\n", X.order_of_key(pii(p,0))+1);
        }
        else
        {
            if( ase<p )
                printf("-1\n");
            else
                printf("%d\n", *X.find_by_order(p-1));
        }
    }
}