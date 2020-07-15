#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[100000007];

int main()
{

        for(int j=2;j<=100000000;j++)
        {
            int i=j;

            while( i%2==0 )
                i/=2;
            while( i%3==0 )
                i/=3;
            while( i%5==0 )
                i/=5;

            arr[j]=i;
        }

        int cnt=1;

        for(int j=2;j<=100000000;j++)
        {
            if(arr[j]==1)
                cnt++;
        }

        cout<<cnt<<endl;

}


