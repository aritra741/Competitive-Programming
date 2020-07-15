#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

set<pii> shoja, ulta;
set<pii> ::iterator it, it2;

int arr[200007];

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0; i<n; i++ )
        scanf("%d", &arr[i]);

    int now= arr[0], idx= 0;
    for( int i=0; i<n; i++ )
    {
        if( arr[i]!=now )
        {
            int I= idx;
            if(I<0)
                I= 0;
            shoja.insert( pii( -1*(i-idx), I ) );
            ulta.insert( pii( idx, (i-I) ) );
            idx= i;
            now= arr[i];
        }
    }

    shoja.insert( pii( -1*(n-idx), idx ) );
    ulta.insert( pii( idx, n-idx  ) );

    int ans= 0;
    while( !shoja.empty() )
    {
        ans++;

        it= shoja.begin();
        pii p= (*it);

        shoja.erase(it);
        it= ulta.lower_bound( pii( p.second, (-1)*p.first ) );
        ulta.erase( it );

        if( p.second and p.second<n-1 )
        {
            it= ulta.lower_bound( pii(p.second, (-1)*p.first) );
            pii j= (*it);

            if( it!=ulta.begin() and it!=ulta.end() )
            {
                it--;
                it2= it;
                it++;
                pii k= (*it2);

                if( arr[k.first]==arr[j.first] )
                {
                    ulta.erase(it);
                    ulta.erase(it2);
                    shoja.erase( shoja.find( pii((-1)*j.second, j.first) ) );
                    shoja.erase( shoja.find( pii((-1)*k.second, k.first) ) );

                    ulta.insert( pii( k.first, k.second+j.second ) );
                    shoja.insert( pii(  -1*(k.second+j.second), k.first ) );
                }
            }
        }
    }

    cout<< ans <<endl;
}
