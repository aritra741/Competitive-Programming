#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool vis[100005];

int main()
{
    ll n;
    cin>>n;
    vector <ll> v;

    for(ll i=1; i<=n; i++)
        v.push_back(i);

    if(n==1)
        cout<<"1"<<endl;
    else if(n==2)
        cout<<"1 2"<<endl;
    else
    {
        int cnt=0;
        int i=0;
        ll init= ceil((double)n/2);

        if(n & 1)
            cout<<init<<" ";
        else
            cout<<++init<<" ";

        int piv=init;
        vis[init]=1;
        bool left=1;
        int prev=cnt;
        while(cnt<n-1)
        {

            bool done=1;
            if(left)
            {
                if(v[n-i-1]!=piv and !vis[v[n-i-1]])
                    {
                        cout<<v[n-i-1]<<" ";
                        vis[v[n-i-1]]=1;
                    }
                else done=0;
                left=0;
            }

            else
            {
                if(v[i]!=piv and !vis[v[i]])
                {
                    cout<<v[i]<<" ";
                    vis[v[i]]=1;
                }
                else done=0;
                left=1;
            }

            if(done)
            cnt++;
            if( !(cnt & 1) and prev!=cnt)
                i++;
            prev=cnt;
        }

        cout<<endl;
    }
}
