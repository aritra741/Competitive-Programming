#include<bits/stdc++.h>
using namespace std;

bool vis[1007];
vector<int>ans;

int main()
{
    int n;
    cin>>n;

    for( int i=2; i<=n; i++ )
        if( !vis[i] )
        {
            int x= i;
            while(x<=n)
                vis[x]= 1, ans.push_back(x), x*= i;
            for( int j=1;i*j<=n;j++ )
                vis[j*i]= 1;
        }

    cout<<ans.size()<<endl;

    for( auto x: ans )
        cout<< x <<" ";
}
