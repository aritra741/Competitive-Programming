#include<bits/stdc++.h>
#define mx 307
using namespace std;

double dp[mx][mx][mx];
bool vis[mx][mx][mx];
double n;

double rec( int x, int y, int z )
{
    if( !(x+y+z) )
        return 0;

    if( vis[x][y][z] )
        return dp[x][y][z];

    double ret= 1;

    if(x)
        ret+= (x/n)*rec( x-1, y, z );
    if(y)
        ret+= (y/n)*rec( x+1, y-1, z );
    if(z)
        ret+= (z/n)*rec( x, y+1, z-1 );
    ret*= n/(x+y+z);

    vis[x][y][z]= 1;

    return dp[x][y][z]= ret;
}

int main()
{
    cin>>n;

    int x= 0, y= 0, z= 0;

    for( int i=0;i<n;i++ )
    {
        int p;
        cin>>p;

        if(p==1)
            x++;
        if(p==2)
            y++;
        if(p==3)
            z++;
    }

    cout<<setprecision(12)<<fixed<< rec( x, y, z ) <<endl;
}
