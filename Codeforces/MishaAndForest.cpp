#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;
int main()
{
    int n;
    cin>>n;

    int deg[n];
    int sv[n];

    for(int i=0; i<n; i++)
        cin>>deg[i]>>sv[i];

    queue <int> q;


    for(int i=0; i<n; i++)
        if(deg[i]==1)
            q.push(i);

    int cnt=0;
    set <pii> st;
    set <pii> ::iterator it;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(deg[sv[u]]<1 or deg[u]<1)
            continue;
        cnt++;
        deg[sv[u]]--;
        if(deg[sv[u]]==1)
            q.push(sv[u]);
        int fir=min( u, sv[u] );
        int sec=max( u, sv[u] );
        if(fir!=sec)
            st.insert( pii(fir, sec) );
        sv[sv[u]]^=u;



    }

    int sz=st.size();
    cout<<sz<<endl;

    for(it=st.begin(); it!=st.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;

}


/*
7
2 2
2 2
1 1
4 7
1 3
1 3
1 3
*/
