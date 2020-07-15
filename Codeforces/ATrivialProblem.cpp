#include <bits/stdc++.h>
using namespace std;

int numZer(int n)
{
    int i=5;
    int ans=0;
    while(i<=n)
    {
        ans+=n/i;
        i*=5;
    }
    return ans;
}

int main()
{
    bool flag=0;
    vector <int> v;
    int m;
    int i;
    int cnt=0;
    cin>>m;
    for(int i=1;; i++)
    {
        if(numZer(i)==m)
        {
            flag=1;
            v.push_back(i);
            cnt++;
            if(cnt==5)
                break;
        }
        if(numZer(i)>m)
            break;
    }
    if(flag==0)
        cout<<0<<endl;
    if(flag==1)
    {
        cout<<5<<endl;
        for(int i=0; i<5; i++)
            cout<<v[i]<<" ";
    }

}
