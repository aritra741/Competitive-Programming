#include<bits/stdc++.h>
using namespace std;

vector<int>v;

int main()
{
    int n;
    int mx= -1, sum= 0, last= 0;
    int arr[n+5], mn= 1e6;

    for( int i=1;i<=n;i++ )
    {
        int p;
        cin>>p;

        if(sum)
            sum+= abs(last-p);
        else
            last= p;

        mn= min( mn, p );

        v.push_back(p);


    }

}
