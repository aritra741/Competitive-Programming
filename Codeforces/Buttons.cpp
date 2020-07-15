#include<bits/stdc++.h>
#define ll long long
using namespace std;

int orig;

ll rec( int n )
{
    if(n==1)
        return 1;
    return (orig-n+1)*(n-1)+1+rec( n- 1);
}

int main()
{
    cin>>orig;
    cout<< rec(orig) <<endl;
}
