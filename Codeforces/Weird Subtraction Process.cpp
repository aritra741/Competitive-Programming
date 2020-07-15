#include <iostream>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    while(1)
    {
        if(n==0 || m==0)
            break;
        if(n>=(m+m))
            n=n%(m+m);
        else if(m>=(n+n))
            m=(m%(n+n));
        else break;
    }
    cout<<n<<" "<<m;
    return 0;
}
