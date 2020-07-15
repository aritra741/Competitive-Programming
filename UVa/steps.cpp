#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        ll p,q;
        cin>>p>>q;
        p++,q--;

        ll increase=1;
        ll cnt=0;
        ll diff=q-p-2;
        ll firstHalf= ceil((double)diff/2.0);
        //firstHalf++;
        ll secondHalf= firstHalf;
        if (firstHalf & 1)
            secondHalf--;
        ll ans= secondHalf+firstHalf;

        cout<<ans<<endl;

    }

}
