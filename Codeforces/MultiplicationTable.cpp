#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;

    int cnt= 0;
    for(int i=1;i<=sqrt(x);i++)
        if(x%i==0 and x/i<=n)
            cnt+=2, cnt=(i*i==x)?cnt-1:cnt;

    cout<< cnt <<endl;
}
