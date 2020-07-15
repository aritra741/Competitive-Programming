#include <iostream>
using namespace std;

int main()
{
    int n,sum=0;cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        if(num[i]<0)
            num[i]=-num[i];
        sum+=num[i];
    }

    cout<<sum;
    return 0;
}
