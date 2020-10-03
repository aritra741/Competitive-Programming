#include <bits/stdc++.h>
#define ll long long
#define p 257
#define p2 311
#define mod 1000000007
#define mod2 1000002727
#define pii pair<ll,ll>
using namespace std;

vector<ll> pre[200007][2];
int sz[200007];
ll Pow[4000007], Pow2[4000007];

void precal()
{
    Pow[0]= 1;
    for( ll i=1; i<4000007; i++ )
        Pow[i]= (Pow[i-1]*p)%mod;
    Pow2[0]= 1;
    for( ll i=1; i<4000007; i++ )
        Pow2[i]= (Pow2[i-1]*p2)%mod2;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precal();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        string s[n+5];
        int zo= 0, oz= 0, o= 0, z= 0;

        map<pii,int>mp;

        for( int i=0;i<n;i++ )
        {
            cin>>s[i];

            if(s[i][0]=='0' and s[i].back()=='1')
                zo++;
            if(s[i][0]=='1' and s[i].back()=='0')
                oz++;
            
            if( s[i][0]==s[i].back() and s[i][0]=='0' )
                z++;
            if( s[i][0]==s[i].back() and s[i][0]=='1' )
                o++;
            
            ll h1= 0;
            for( int j=0;j<s[i].size();j++ )
                h1= ( h1+(Pow[j+1]*(s[i][j]-'0'+1) ) )%mod;
            ll h2= 0;
            for( int j=0;j<s[i].size();j++ )
                h2= ( h2+(Pow2[j+1]*(s[i][j]-'0'+1) ) )%mod2;
            
            mp[{h1,h2}]++;
        }

        if( !oz and !zo and o and z )
        {
            cout<<"-1\n";
            continue;
        }

        if( abs(zo-oz)<=1 )
        {
            cout<<"0\n\n";
            continue;
        }

        std::vector<int> ans;

        for( int i=0;i<n;i++ )
        {
            if( abs(zo-oz)<=1 )
                break;

            if( s[i][0]==s[i].back() )
                continue;   

            if( s[i][0]=='0' and zo<=oz )
                continue;

            if( s[i][0]=='1' and oz<=zo )
                continue;

            ll h1= 0;
            for( int j=0;j<s[i].size();j++ )
                h1= ( h1+(Pow[j+1]*(s[i][j]-'0'+1) ) )%mod;

            ll h2= 0;
            for( int j=0;j<s[i].size();j++ )
                h2= ( h2+(Pow2[j+1]*(s[i][j]-'0'+1) ) )%mod2;
            
            pii pp= {h1,h2};

            reverse( s[i].begin(), s[i].end() );

            h1= 0;
            for( int j=0;j<s[i].size();j++ )
                h1= ( h1+(Pow[j+1]*(s[i][j]-'0'+1) ) )%mod;

            h2= 0;
            for( int j=0;j<s[i].size();j++ )
                h2= ( h2+(Pow2[j+1]*(s[i][j]-'0'+1) ) )%mod2;
            
            if( mp[{h1,h2}] )
                continue;

            if( s[i][0]=='1' )
                oz++, zo--;
            else
                zo++, oz--;

            mp[{h1,h2}]++;
            mp[pp]--;

            ans.push_back(i+1);
        }

        if(abs(zo-oz)>1)
        {
            cout<<"-1\n";
            continue;
        }

        cout<< ans.size() <<"\n";

        for( auto x: ans )
            cout<<x<<" ";

        cout<<"\n";
    }
}