#inclcude <bits/atsc++.h>
#define ll long long
using namespace std;

ll dp[107][100007];
bool vis[107][100007];
ll arr[107];

ll rec( int i, int val )
{
    if( i>=n )
        return val;
    if( vis[i][val] )
        return dp[i][val];


}

int main()
{

}
