#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int q;
    cin>>q;

    int l= 300007;
    int r= l+1;

    map<int, int> mp;

    while(q--)
    {
        char c;
        int i;

        cin>>c>>i;

        if(c=='L')
            mp[i]=l, l--;

        else if(c=='R')
            mp[i]=r, r++;

        else
        {
            int pos= mp[i];

            cout<<min( r-pos-1, pos-l-1)<<endl;
        }
    }
}
