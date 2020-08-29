#include <bits/stdc++.h>
#define ll long long
#define mset(x,i) memset(x, i, sizeof(x))
using namespace std;

bool arr[1010];
int primes[1000];
vector<int> dv[1005];
int cnt=0;
int lvl[1010];
bool vis[1010];

void sieve(void)
{
    arr[0]=arr[1]=1;

    for(ll i=2;i<=1000;i++)
    {
        if(!arr[i])
        {
            primes[cnt++]=i;
            for(ll j=i*i;j<=1000;j+=i)
                arr[j]=1;
        }
    }
}

void preCalc(void)
{
    for(int i=0;i<cnt;i++)
    {
        for(ll j=2;primes[i]*j<=1000;j++)
            dv[primes[i]*j].push_back(primes[i]);
    }
}

int main()
{
    sieve();
    preCalc();
//
//    for(int i=20;i<=500;i++)
//    {
//        cout<<i<<"->";
//        for(int j=0;j<dv[i].size();j++)
//            cout<<dv[i][j]<<" ";
//        cout<<endl;
//    }

    int tc;
    cin>>tc;

    for(int i=1;i<=tc;i++)
    {
        mset(lvl,0x3f);
        mset(vis, 0);

        int s,t;
        cin>>s>>t;
        cout<<"Case "<<i<<": ";
        int sz=dv[s].size();

        if( !sz and s!=t )
        {
            cout<<"-1"<<endl;
            continue;
        }

        if(s==t)
        {
            cout<<"0"<<endl;
            continue;
        }

        queue<int> q;
        lvl[s]=0;
        q.push(s);
        vis[s]=1;
        bool found=0;

        while(!q.empty())
        {

            int u=q.front();
            if(u==t)
                break;
            q.pop();

            for(int j=0;j<dv[u].size();j++)
            {
                int num=dv[u][j]+u;
                if(num==t)
                    found=1;
                if(num<=t and !vis[num])
                    {
                        q.push(num);
                        vis[num]=1;
                        lvl[ num ]=min(lvl[ u ]+1,lvl[num]);
                    }

            }
        }

        if(found)
            cout<<lvl[t]<<endl;
        else
            cout<<"-1"<<endl;


    }
}
