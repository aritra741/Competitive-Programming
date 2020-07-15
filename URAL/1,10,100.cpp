#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        unsigned long long k,ans;
        cin>>k;
        unsigned long long sq= sqrt(8*k-7);
        if(sq*sq==8*k-7)
            cout<<"1 ";
        else
            cout<<"0 ";
    }
}
