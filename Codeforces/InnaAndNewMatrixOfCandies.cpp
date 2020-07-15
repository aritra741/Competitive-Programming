#include <bits/stdc++.h>
using namespace std;

char grid[1010][1010];
int diff[1010];

int main()
{
    int n,m;
    cin>>n>>m;

    bool inv= 0;
    for(int i=0; i<n; i++)
    {
        int l,r;
        for(int j=0; j<m; j++)
        {
            cin>> grid[i][j];
            if(grid[i][j]=='S')
                r= j;
            else if((grid[i][j]=='G'))
                l= j;
        }

        diff[i]= r-l;
        if(l>r)
            inv= 1;
    }

    if(inv)
    {
        cout<< "-1" <<endl;
        return 0;
    }

    int cnt= 0, sub= 0,tmp= 0;

    for(int k=0; k<1010; k++)
    {
        int mn= 1e9;
        for(int i=0; i<n; i++)
        {
            if( diff[i]-sub>0 )
                mn= min(mn,diff[i]-sub);
        }

        if(mn<1e9)
            sub+= mn;
        if(tmp!=sub)
            cnt++;
        tmp= sub;
    }


    cout<< cnt <<endl;
}
