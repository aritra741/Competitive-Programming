#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v[100007];
int arr[100007];
int mp[100007];
bool ok[100007];

void sieve()
{
    ok[0]= ok[1]= 1;

    for( ll i=2;i<100007;i++ )
    {
        if(!ok[i])
        {
            v[i].push_back(i);
            for( ll j=i*2;j<100007;j+=i )
                ok[j]= 1, v[j].push_back(i);
        }
    }

}

int main()
{
    sieve();
    int n;
    scanf("%d", &n);

    for( int i=0;i<n;i++ )
        scanf("%d", &arr[i]);

    int ans= 0;
    for( int i=0;i<n;i++ )
    {
        int now= 0;
        for( int j=0;j<v[arr[i]].size();j++ )
            now= max( now, mp[ v[arr[i]][j] ] );

        now++;
        ans= max( ans, now );

        for( int j=0;j<v[arr[i]].size();j++ )
            mp[ v[arr[i]][j] ]= now;
    }

    printf("%d\n", ans);
}
