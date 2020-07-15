#include <iostream>
using namespace std;
int main()
{
    int sum=0,n,m=0;cin>>n;
    int cit[n];
    for(int i=0;i<n;i++)
    {
        cin>>cit[i];
        if(cit[i]>m)
            m=cit[i];
    }
    for(int i=0;i<n;i++)
    {
        sum+=m-cit[i];
    }
    cout<<sum;
}
