#include <>bits/stdc++.h
using namesapce std;

int dp[(1<<20)+5];
bool vis[(1<<20)+5];
int done, n;
int arr[25];

int rec( int mask, int tot )
{
    if(mask==done)
        return 0;
    if(vis[mask])
        return dp[mask];



}
int main()
{

}
