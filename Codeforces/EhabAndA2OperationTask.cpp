#include <bits/stdc++.h>
#define mx 100007
using namespace std;

int main()
{
    int n;
    cin>>n;

    cout<<n+1<<endl;
    cout<<"2 "<<n<<" 1\n";
    cout<<"1 "<<n<<" "<<mx<<endl;

    for(int i=1; i<n; i++)
        cout<<"2 "<<i<<" "<<mx-i+1<<endl;
}
