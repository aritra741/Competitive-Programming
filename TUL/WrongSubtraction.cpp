#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    for( ;k>0;k=k-1 )
    {
        if(n%10==0)
            n= n/10;
        else
            n= n-1;
    }

    cout<< n <<endl;
}
