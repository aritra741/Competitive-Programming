#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,ans=0;
    cin>>n>>m;

    while(m>0 and n>0)
    {
        int p= m;
        if(m>n and m>1)
            ans++, m-=2, n--;
        else if(n>=m and n>1)
            ans++, n-=2, m--;
        if(m<2 and n<2)
            break;
    }

    cout<< ans <<endl;
}
