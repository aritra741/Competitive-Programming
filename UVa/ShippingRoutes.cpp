#include <bits/stdc++.h>
using namespace std;



int main()
{
    int tc;
    cin>>tc;

    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;;
    for(int i=1; i<=tc; i++)
    {

        int node,edge,query;
        cin>>node>>edge>>query;
        cout<<"DATA SET  "<<i<<endl<<endl;
        int lev[node+1];
        int vis[node+1];
        vector <int> vc[node+1];
        queue <int> qu;
        string s,s1;
        int cnt=1;
        map<string, int> mp;
        for(int j=0; j<node; j++)
        {
            cin>>s;
            mp[s]=cnt++;
        }

        for(int j=0; j<edge; j++)
        {
            cin>>s;
            cin>>s1;
            vc[mp[s]].push_back(mp[s1]);
            vc[mp[s1]].push_back(mp[s]);
        }
        for(int q=0; q<query; q++)
        {

            memset(vis, 0, sizeof(vis));
            memset(lev, 0, sizeof(lev));

            lev[0]=0;
            vis[0]=1;
            string st,t;
            int w;
            cin>>w>>st>>t;
            qu.push(mp[st]);
            vis[mp[st]]=1;
            lev[mp[st]]=0;
            while(!qu.empty())
            {

                int u=qu.front();

                qu.pop();
                if(u==mp[t])
                    break;
                for(int it=0; it<vc[u].size(); it++)
                {

                    if(vis[vc[u][it]]==0)
                    {

                        lev[vc[u][it]]=lev[u]+1;
                        vis[vc[u][it]]=1;
                        if(vc[u][it]==mp[t])
                            break;
                        qu.push(vc[u][it]);

                    }
                }
            }
            if(vis[mp[t]])
                cout<<"$"<<lev[mp[t]]*w*100<<endl;
            else
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
        }
        cout<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
}
