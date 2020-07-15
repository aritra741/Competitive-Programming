#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
       // getchar();
        int n,f,p;
        cin>>f>>n;

        ll d[n+5][n+5];
        bool fire[n+5];
        int fs[f+5];
        memset(fire, 0, sizeof(fire));

        for(int i=0; i<f; i++)
        {
            cin>>p;
            fire[p]= 1;
            fs[i]= p;
        }

        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
            {
                if(i==j)
                    d[i][j]= 0LL;
                else
                    d[i][j]= 1000000000000000LL;
            }

        getchar();
        while(1)
        {
            string s;
            getline(cin, s);
            stringstream ss;
            ss<<s;

            if(s.empty())
                break;
            int p,q;
            ll w;
            ss>>p>>q>>w;
            d[p][q]= min( d[p][q], w );
            d[q][p]= min( d[q][p], w );
        }

        if(n==1)
        {
            printf("1\n");

            if(tc)
                printf("\n");

            continue;
        }

        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    d[i][j]= min( d[i][j], d[i][k]+d[k][j] );

        ll mxVal= 1000000000000000LL;
        int mxNode= 1000;
        ll fromstat[n+5];

        for(int i=0; i<=n; i++)
        {
            if(fire[i])
                fromstat[i]= 0;
            else
                fromstat[i]= 1000000000000000LL;
        }

        for(int i=0; i<f; i++)
            for(int j=1; j<=n; j++)
            {
                if(fire[j])
                    continue;
                fromstat[j]= min( fromstat[j], d[fs[i]][j] );
            }

        for(int i=1; i<=n; i++)
        {
            ll mx= -1;
            for(int j=1; j<=n; j++)
            {
                ll temp= min(fromstat[j], d[i][j]);
                mx= max(temp, mx);
            }

            if(mx==mxVal)
                mxNode= min( mxNode, i );
            else if(mx<mxVal)
                mxVal= mx, mxNode= i;
        }

        printf("%d\n", mxNode);

        if(tc)
            printf("\n");
    }
}
