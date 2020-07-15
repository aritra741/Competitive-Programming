#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,rem;
    cin>>n>>m;
    int i= 1;

    while(1)
    {
        if(i%n==0)
            i= n;
        if(i>m)
            break;
        m-=i;
        i= (i+1)%n;
    }

    cout<< m <<endl;
}
