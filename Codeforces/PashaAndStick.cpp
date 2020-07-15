#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;

    if(n%2==0)
        cout<<setprecision(0)<<fixed<<ceil((double)n/4)-1<<endl;
    else
        cout<<"0"<<endl;
}
