#include <bits/stdc++.h>
using namespace std;

string s[100];
bool vis[100][100];
int r=-1,c=-1;
int moves1[]= {1,0,-1,0,1,-1,1,-1};
int moves2[]= {0,1,0,-1,1,-1,-1,1};
int cnt;

bool isvalid( int i, int j )
{
    if(i<0 or j<0)
        return 0;
    if(i>=r or j>=c)
        return 0;
    if(s[i][j]=='L')
        return 0;
    return 1;
}

void dfs( int p, int q )
{
    vis[p][q]= 1;
    cnt++;
    for(int i=0; i<8; i++)
    {
        int u= p+moves1[i];
        int v= q+moves2[i];

        if( !vis[u][v] and isvalid(u,v) )
            dfs(u,v);
    }
}

int main()
{
    int tc;
    cin>>tc;
    getchar();
    for(int t=0; t<=tc; t++)
    {
        for(int i=0; i<100; i++)
            s[i].clear();
        int i;
        r=-1, c=-1;
        for(i=0;; i++)
        {
            string dummy;
            getline(cin,dummy);

            if(dummy[0]==0)
                break;


            else if(dummy[0]!='L' and dummy[0]!='W')
            {
                stringstream ss;
                ss<<dummy;

                int j= 0, arr[3];

                while(ss>>arr[j++]);

                cnt= 0;

                if(r==-1 and c==-1)
                    r= i, c= s[i-1].size();

                cnt= 0;
                dfs( arr[0]-1, arr[1]-1 );

                cout<<cnt<<endl;
                memset( vis, 0, sizeof(vis) );

            }
            else
                s[i]= dummy;
        }

        if(t and t<tc)
            cout<<endl;
    }
}
