#include <bits/stdc++.h>
using namespace std;

vector<int> v[60];

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);

    for( int i=0; i<m; i++ )
    {
        int p;
        scanf("%d", &p);

        for( int j=0; j<p; j++ )
        {
            int q;
            scanf("%d", &q);

            v[i].push_back(q);
        }

        sort( v[i].begin(), v[i].end() );
    }

    for( int i=0; i<m; i++ )
    {
        for( int j=i+1; j<m; j++ )
        {
            bool f= 0;

            for( int k=0; k<v[i].size(); k++ )
            {
                if( binary_search( v[j].begin(), v[j].end(), v[i][k] ) )
                {
                    f= 1;
                    break;
                }
            }

            if( !f )
                return cout<<"impossible\n", 0;
        }
    }

    cout<<"possible\n";
}
