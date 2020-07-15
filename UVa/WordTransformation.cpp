#include <bits/stdc++.h>
using namespace std;

map<string, int> lvl;
map<string, int> vis;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        lvl.clear();
        vis.clear();

        string dict[500];
        int cnt=0;

        while(1)
        {
            cin>>dict[cnt++];
            if(dict[cnt-1]=="*")
                break;
        }

        getchar();

        while(1)
        {
            string s,st,t;
            getline(cin,st);

            if(st[0]==0)
                break;

            stringstream ss;
            ss<<st;
            ss>>s>>t;

            lvl.clear();
            vis.clear();

            queue<string> q;
            lvl[s]= 0;
            vis[s]= 1;
            q.push(s);

            while(!q.empty())
            {
                string u= q.front();
                int len1= u.size();
                q.pop();

                if(u==t)
                    break;

                for(int i=0; i<cnt-1; i++)
                {
                    int chng= 0;
                    string v= dict[i];

                    int len2= v.size();

                    if(len1!=len2)
                        continue;
                    if( vis[v] )
                        continue;

                    for(int j=0; j<len1; j++)
                        if( u[j]!=v[j] )
                            chng++;

                    if(chng==1)
                    {
                        vis[v]= 1;
                        lvl[v]=lvl[u]+1;

                        if(v==t)
                            break;

                        q.push(v);
                    }

                }
            }

            cout<<s<<" "<<t<<" "<<lvl[t]<<endl;

        }

        if(tc)
            cout<<endl;
    }
}
