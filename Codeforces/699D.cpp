#include<bits/stdc++.h>
#define mx 200007
using namespace std;

int par[mx], Size[mx];
bool jhamela[mx];
int cntp, cntq, root;

int Find(int u)
{
    if(u==par[u])
        return u;
    return par[u]= Find(par[u]);
}

void unite( int u, int v )
{
    int paru= par[u];
    int parv= par[v];

    if(paru!=parv)
    {
        if( Size[paru]<Size[parv] )
           Size[parv]+= Size[paru], par[paru]= parv;
        else
           Size[paru]+= Size[parv], par[parv]= paru;
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n+5];

    for( int i=1;i<=n;i++ )
        par[i]= i, Size[i]= 1;

    for( int i=1;i<=n;i++ )
    {
        cin>>arr[i];

        if( arr[i]==i )
            root= i, jhamela[i]= 1, cntp++;
        else if( Find(arr[i])==Find(i) )
            jhamela[i]= 1, cntq++;
        else
            unite(arr[i],i);
    }

    int ans= 0;

    for( int i=1;i<=n;i++ )
    {
        if( jhamela[i] )
        {
            if( !root )
                root= i, arr[i]= i, ans++;
            else if( arr[i]!=root )
                arr[i]= root, ans++;
        }
    }

    cout<<ans<<endl;

    for( int i=1;i<=n;i++ )
        cout<< arr[i] <<" ";
}
