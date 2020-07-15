#include <bits/stdc++.h>
#define ll long long
using namespace std;

int par[1100];
struct edge
{
    int u,v,cost;
} edges[15000];

bool cmp(const edge &a, const edge &b)
{
    return a.cost<b.cost;
}

ll gcd(ll p, ll q)
{
    ll a= max(p,q);
    ll b= min(p,q);

    if(b==0)
        return a;
    gcd(a%b, b);
}

int Find(int x)
{
    if(par[x]!=x)
        par[x]=Find(par[x]);
    return par[x];
}

void Union(int x, int y)
{
    int par1= Find(x);
    int par2= Find(y);

    par[par1]=par2;
}

int main()
{
    int tc;
    cin>>tc;
    int p,q,w;

    for(int t=1; t<=tc; t++)
    {
        int cnt=-1;
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
            par[i]=i;
        while(1)
        {
            cin>>p>>q>>w;
            if(p+q+w==0)
                break;
            cnt++;
            edges[cnt].u=p;
            edges[cnt].v=q;
            edges[cnt].cost=w;
        }

        sort(edges, edges+cnt+1, cmp);

        int edgeCount=0;
        double best=0;

        for(int i=0;i<=cnt;i++)
        {
            if(edgeCount==n)
                break;
            int p=edges[i].u;
            int q=edges[i].v;
            int w=edges[i].cost;

            if( Find(p)!= Find(q) )
            {
                Union(p,q);
                edgeCount++;
                best+=w;
            }
        }

        for(int i=0;i<=n;i++)
            par[i]=i;

        edgeCount=0;
        double worst=0;

        for(int i=cnt;i>=0;i--)
        {
            if(edgeCount==n)
                break;
            int p=edges[i].u;
            int q=edges[i].v;
            int w=edges[i].cost;


            if( Find(p)!= Find(q) )
            {
                Union(p,q);
                edgeCount++;
                worst+=w;
            }
        }

        double ave=(best+worst)/2.0;

        if(ave!= (long long) ave)
        {
            long long numer= ave*100;
            long long denom=100;
            long long g= gcd(numer, denom);

            cout<<"Case "<<t<<": "<<numer/g<<"/"<<denom/g<<endl;
        }

        else
        {
            cout<<"Case "<<t<<": "<<ave<<endl;
        }

    }



}
