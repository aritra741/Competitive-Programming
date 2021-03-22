#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define pii pair<int,int>
#define pci pair<int,int>
#define ff first
#define ss second
#define piii pair<int,pii>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        map<char, int>mp;

        for ( int i = 0; i < n; i++ )
            mp[s[i]]++;

        string t;
        cin >> t;

        sort( t.begin(), t.end() );

        bool ok= 1;

        for ( int i = 0; i < n; i++ )
        {
            for ( char j = 'b'; j <= t[i]; j++ )
            {
                if (mp[j - 1] >= k)
                {
                    mp[j] += (mp[j - 1]/k)*k;
                    mp[j - 1] -= (mp[j - 1]/k)*k;
                }
            }

            bool f= 0;

            for ( char j = 'a'; j < t[i]; j++ )
            {
                if (mp[j] >= k)
                {
                    mp[j]-= j;
                    f= 1;
                    break;
                }
            }

            if(!f)
            {
                if( mp[t[i]] )
                {
                    f= 1;
                    mp[t[i]]--;
                }
                else
                    ok= 0;
            }
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}