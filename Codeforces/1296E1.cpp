#include<bits/stdc++.h>
#define mx 207
using namespace std;

vector<int>adj[mx];
int col[mx];

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    for( int i=0; i<n; i++ )
        for( int j=i+1; j<n; j++ )
            if( s[j]<s[i] )
                adj[i].push_back(j),
                    adj[j].push_back(i);

    bool f= 1;

    for( int i=0; i<n; i++ )
    {
        if(col[i])
            continue;

        queue<int>q;
        q.push(i);
        col[i]= 1;

        while(!q.empty())
        {
            int u= q.front();
            q.pop();

            for( int v: adj[u] )
            {
                if( col[v] and col[v]==col[u] )
                {
                    f= 0;
                    break;
                }

                if(!col[v])
                {
                    col[v]= col[u]%2+1;
                    q.push(v);
                }
            }
        }
    }

    if(!f)
        return cout<<"NO\n", 0;

    cout<<"YES\n";
    for( int i=0; i<n; i++ )
        cout<<col[i]%2;

}
