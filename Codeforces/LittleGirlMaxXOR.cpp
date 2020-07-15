#include <bits/stdc++.h>
using namespace std;
priority_queue <int> pq;
int main()
{
    unsigned long long a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<0;
        return 0;
    }
    unsigned long long ans=0;
    stringstream ss;
    string t;

    for(int i=0;i<=60;i++)
    {

        int temp=((b>>i)&1);
        ss<<temp;

    }

    ss>>t;

    reverse(t.begin(), t.end());

    ss=stringstream();
    string p;
    for(int i=0;i<=60;i++)
    {

        int temp=((a>>i)&1);
        ss<<temp;

    }
    ss>>p;
    reverse(p.begin(), p.end());
    int idx;
  //  cout<<t<<endl<<p<<endl;
    for(int i=0;i<=60;i++)
    {
        if(t[i]!=p[i])
        {
            idx=60-i;
           // cout<<idx<<endl;
            break;
        }
    }
//    ans=idx+1;
    ans=(unsigned long long)pow(2, idx+1)-1;
    cout<<ans;

}
