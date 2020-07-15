#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=0; t<tc; t++)
    {
        getchar();
        int n;
        scanf("%d", &n);

        int l[4][n];

        for(int i=0; i<n; i++)
            scanf("%d %d %d %d", &l[0][i], &l[1][i], &l[2][i], &l[3][i]);

        vector <int> fir,sec;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                fir.push_back( l[0][i] + l[1][j] );
                sec.push_back( l[2][i] + l[3][j] );
            }

        int cnt=0;
        int sz= fir.size();

        sort(sec.begin(),sec.end());

        for(int i=0;i<sz;i++)
        {
            int sum= fir[i];

            if(binary_search( sec.begin(), sec.end(), -sum ))
            {
                int add= upper_bound(sec.begin(), sec.end(), -sum) - lower_bound(sec.begin(),sec.end(), -sum) ;
                cnt+=add;
            }

        }

        if(t!=0)
            printf("\n");

        printf("%d\n", cnt);

    }
}
