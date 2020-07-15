#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m,k;
        cin>>n>>m>>k;

        int paabe= min( n/k, m );
        int onno= (m-paabe+k-2)/(k-1);

        cout<< paabe-onno <<endl;
    }
}
