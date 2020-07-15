#include <bits/stdc++.h>
#define ll long long
using namespace std;

unsigned arr[3*100000007];

int main()
{

        for(unsigned j=2;j<=300000000;j++)
        {
            unsigned i=j;

            while( i%2==0 )
                i/=2;
            while( i%3==0 )
                i/=3;
            while( i%5==0 )
                i/=5;

            arr[j]=i;
        }

        int cnt=1;

        for(unsigned j=2;j<=300000000;j++)
        {
            if(arr[j]==1)
                cnt++;
        }

        cout<<cnt<<endl;

}

