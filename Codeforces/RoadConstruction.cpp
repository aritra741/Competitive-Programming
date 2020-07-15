#include <bits/stdc++.h>
using namespace std;
bool node[1001];
int main()
{

    int n,m,t1,t2;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>t1>>t2;
        node[t1]=1;
        node[t2]=1;
    }
    int key;
    for(int i=1;i<=n;i++)
    {
        if(node[i]==0)
        {
            key=i;
            break;
        }
    }
    cout<<(n-1)<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i==key)
            continue;
        else
            cout<<key<< " "<<i<<endl;
    }
}
