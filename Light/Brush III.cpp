#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n,k,w;
int dp[110][110];
int vis[110][110];
int p;

int rec( int i, int cnt )
{
    if( cnt==k )
        return 0;
    if( i>=n )
        return 0;
    if(vis[i][cnt]==p)
        return dp[i][cnt];

    int top= arr[i]+w;
    auto it= upper_bound( arr.begin(), arr.end(), top );
    int pos= it-arr.begin();

    int q1= pos-i+rec( pos, cnt+1 );
    int q2= rec( i+1, cnt );

    vis[i][cnt]= p;

    return dp[i][cnt]= max(q1,q2);
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        cin>>n>>w>>k;
        int dummy;

        for(int i=0; i<n; i++)
        {
            int y;
            cin>>dummy>>y;
            arr.push_back(y);
        }

        sort( arr.begin(),arr.end() );

        cout<<"Case "<<t<<": "<< rec( 0, 0 ) <<endl;
        arr.clear();
    }
}
