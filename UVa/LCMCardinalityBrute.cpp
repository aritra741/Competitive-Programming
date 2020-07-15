#include <bits/stdc++.h>
#define pii pair<int, int>
#define mx 1000007
using namespace std;

vector <int> dv[mx];

int pre()
{
    for(int i=1;i<mx;i++)
    {
        for(int j=i;j<mx;j+=i)
            dv[j].push_back(i);
    }
}

int main()
{
    pre();

    while(1)
    {
        int n;
        cin>>n;

        if(!n)
            break;

        int sz= dv[n].size();

        set <pii> st;

        for(int i=0;i<sz;i++)
        {
            for(int j=i;j<sz;j++)
            {
                int u= dv[n][i];
                int v= dv[n][j];

                if( u*v/__gcd(u,v)==n )
                    st.insert( pii(u,v) );
            }
        }

        cout<<dv[n].size()<<" "<<st.size()<<endl;
    }
}
