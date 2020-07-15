#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ncr[780][11];

void init()
{
    for( int i=0;i<780;i++ )
        ncr[i][0]= 1;
    for( int i=1;i<780;i++ )
        for( int j=1;j<=min(i,7);j++ )
            ncr[i][j]= ncr[i-1][j-1]+ncr[i-1][j];
}

int main()
{
    init();

    int n;
    cin>>n;

    cout<< ncr[n][5]+ncr[n][6]+ncr[n][7] <<endl;
}
