#include <bits/stdc++.h>
using namespace std;


int cnt( int n, int p, int big  )
{
    if( pow(n, p) == big )
        return 1;
    if( pow(n, p) > big )
        return 0;

    return cnt(n+1, p, big- pow(n, p) )+ cnt( n+1, p, big );
}

int main()
{
    int big;
    cin>>big;
    int p;
    cin>>p;
    int ans= cnt( 1, p, big );
    cout<<ans;

}
