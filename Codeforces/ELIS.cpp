#include <bits/stdc++.h>
#define inf 30
using namespace std;

vector<int> L(15), I(15);
vector<int> ::iterator it;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<15;i++)
        I[i]= inf;
    I[0]= -inf;

    int arr[n+1];

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    for(int i=1;i<=n;i++)
    {
        it= lower_bound( I.begin(), I.end(), arr[i] );
        int pos= it-I.begin();

        I[pos]= arr[i];
        L[i]= pos;
    }

    int ans= 1;

    for(int i=1;i<=n;i++)
        ans= max(ans, L[i]);

    cout<<ans<<endl;

}
