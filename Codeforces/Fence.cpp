#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull n,h;
    cin>>n>>h;
    ull mn=1000000008;
    ull curr=0;
    ull temp;
    ull cnt=0;
    ull idx=1;
    ull arr[n];
    for(ull i=0; i<=n; i++)
    {

        if(cnt>=h)
        {
            if(curr<mn)
            {
//              cout<<curr<<" "<<i<<endl;
                idx=i-h+1;
                mn=curr;

            }
//          cout<<i-h+1<<endl;
            curr-=arr[i-h];

        }
        if(i==n)
            break;
        cin>>arr[i];
        curr+=arr[i];
        //      cout<<curr<<" "<<idx<<endl;
        cnt++;


    }
    cout<<idx;

}
