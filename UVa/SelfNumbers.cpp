#include <bits/stdc++.h>
#define mx 1000007
using namespace std;

bool arr[mx];

int bhaag( int x )
{
    int tot=0;

    while(x)
    {
        tot+=x%10;
        x/=10;
    }

    return tot;
}

void sieve()
{
    for(int i=1; i<mx; i++)
    {
        if(!arr[i])
        {

            for(int j=i+bhaag(i); j<mx; j+=bhaag(j))
            {
                if(arr[j])
                    break;
                arr[j]=1;
            }
        }
    }
}

int main()
{
    sieve();
    for(int i=1; i<=mx-7; i++)
        if(!arr[i])
            cout<<i<<endl;

}
