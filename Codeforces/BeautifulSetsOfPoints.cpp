#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int mn=min(n,m);
    cout<<mn+1<<endl;
    for(int i=0;i<=mn;i++)
        cout<<i<<" "<<mn-i<<endl;
}
