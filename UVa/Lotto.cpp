#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll,ll>
using namespace std;

int arr[20];
int n;

void rec( int i, vector <int> v )
{
    if(v.size()==6)
    {
        cout<<v[0];
        for(int i=1; i<6; i++)
            cout<<" "<<v[i];
        cout<<endl;
        return;
    }

    if(i>=n)
        return;

    v.push_back( arr[i] );
    rec( i+1, v );
    v.erase( v.end()-1);

    rec( i+1, v );
}
int main()
{
    bool first=1;

    while(1)
    {
        cin>>n;

        if(!n)
            break;

        for(int i=0; i<n; i++)
            cin>>arr[i];

        vector <int> v;

        if(first)
            first=0;
        else
            cout<<endl;

        rec(0, v);

    }

}
