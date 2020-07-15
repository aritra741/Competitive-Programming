#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

int main()
{
    int a,b;
    cin>>a>>b;

    int mn= min( a,b );

    for( int i=1;i*i<=mn;i++ )
    {
        if( a%i==0 and b%i==0 )
            ans.push_back(i);

        if( b%i==0 and a%(b/i)==0 and i*i!=b )
            ans.push_back(b/i);

        if( a%i==0 and b%(a/i)==0 and i*i!=a )
            ans.push_back(a/i);
    }

    sort( ans.begin(),ans.end() );

    int q;
    cin>>q;

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int pos1= upper_bound( ans.begin(),ans.end(),r )-ans.begin();
        int pos= pos1-1;

        if( ans[pos]>=l and ans[pos]<=r )
            cout<< ans[pos] <<endl;
        else
            cout<<"-1\n";
    }
}
