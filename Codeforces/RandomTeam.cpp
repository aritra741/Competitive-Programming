#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull n,m;
    cin>>n>>m;
    if(m==n)
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    else if(m==1)
    {
        ull ans= n*(n-1)/2;
        cout<<ans<<" "<<ans<<endl;
        return 0;
    }

    ull t= (n-m+1);
    ull mx= t*(t-1)/2;
    ull it= n%m;
    ull fix= n/m;

    ull first = ((fix)*(fix-1)/2)*(m-it);
    ull second = ((fix+1)*(fix)/2)*it;
    //cout<<first<<" "<<second<<endl;
    cout<<first+second<<" "<<mx<<endl;

}
