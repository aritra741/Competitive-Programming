#include <iostream>
using namespace std;

int main()
{
    int n,m,z,i=1,num=0;cin>>n>>m>>z;
    while(m*i<=z)
    {

        if((m*i)%n==0)
            num++;
        i++;
    }
    cout<<num;
}
