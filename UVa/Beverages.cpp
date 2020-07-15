#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int tc=1;
    while(cin>>n)
    {
        string bev;
        list <string> st;
        list <string> ::iterator stit;
        map<string,int> indegree;
        map<string,int> stToint;
        map<int,string> intTost;
        map<string,int> ::iterator it;
        vector <int> adj[n];
        vector <string> t;
        int cnt=0;
        for(int i=0;i<n;i++)
            {
                cin>>bev;
                st.push_back(bev);
                stToint[bev]=cnt++;
                intTost[cnt-1]=bev;
            }

        int m;
        cin>>m;

        for(int i=0;i<m;i++)
        {
            string p,q;
            cin>>p>>q;
            adj[ stToint[p] ].push_back(stToint[q]);
            indegree[p]+=0;
            indegree[q]++;
        }
        getchar();

        while(!st.empty())
        {
            int u;
            for(stit=st.begin();stit!=st.end();stit++)
            {
                string s=*stit;
                if(indegree[*stit]==0)
                {
                    u=stToint[*stit];
                    t.push_back(*stit);
                    st.remove(*stit);

                    break;
                }
            }
            //cout<<intTost[u]<<endl;
            for(int i=0;i<adj[u].size();i++)
            {  // cout<<intTost[u]<<" "<<intTost[ adj[u][i] ]<<endl;
                indegree[ intTost[adj[u][i] ] ]--;
            }


        }
        cout<<"Case #"<<tc++<<": Dilbert should drink beverages in this order: ";
       for(int i=0;i<t.size();i++)
            {
                cout<<t[i];
                if(i!=t.size()-1)
                    cout<<" ";
            }
        cout<<"."<<endl<<endl;
    }
}
