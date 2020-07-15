#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q=1,l=0;
    int ifp[51];
    int prime[51];
    map < int, int > mp;
    memset(ifp, -1, sizeof(ifp));
    for(int i=2;i<=50;i+=2)
        ifp[i]=0;
    ifp[2]=1;
    ifp[1]=0;
    prime[0]=2;
    for(int i=3;i<=50;i++)
        for(int q=1;(i*q)<=50;q++)
            {

                if(ifp[i]==-1)
                    {

                    ifp[i]=1;
                    l++;
                    prime[l]=i;
                    mp[prime[l-1]]=prime[l];
                    }
                if(ifp[i*q]==-1)
                    ifp[i*q]=0;


            }

    int n,m;cin>>n>>m;
    if(ifp[m]==0)
        cout<<"NO";
    else
    {
        if(mp[n]==m)
            cout<<"YES";
        else
            cout<<"NO";
    }

}
