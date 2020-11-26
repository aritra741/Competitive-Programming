#include<bits/stdc++.h>
#define ll long long
#define mx 300007
using namespace std;

int arr[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n;
    cin>>n;
    cin >> s;

    std::vector<int> aa,bb;

    for( int i=0;i<n;i++ )
    {
        if( s[i]=='A' )
            aa.push_back(i);
        else
            bb.push_back(i);
    }

    ll baad= 0;

    for( int i=0;i<n;i++ )
    {
        if(s[i]=='A')
        {
            int pos= upper_bound( aa.begin(), aa.end(), i )-aa.begin();
            
            if(pos==aa.size())
                pos= n;
            else
                pos= aa[pos];

            baad+= pos-i;

            pos= upper_bound( bb.begin(), bb.end(), i )-bb.begin();
            
            if( pos!=bb.size() and bb[pos]>i+1 )
                baad++;
        }
        else
        {
            int pos= upper_bound( bb.begin(), bb.end(), i )-bb.begin();

            if(pos==bb.size())
                pos= n;
            else
                pos= bb[pos];

            baad+= pos-i;

            pos= upper_bound( aa.begin(), aa.end(), i )-aa.begin();
            
            if( pos!=aa.size() and aa[pos]>i+1 )
                baad++;
        }
    }   

    ll ans= n;
    ans*= (n+1);
    ans/= 2;

    ans-= baad;

    cout<< ans <<"\n";
}


