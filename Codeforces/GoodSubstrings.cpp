#include <bits/stdc++.h>
using namespace std;

struct trie
{
    trie *nxt[26];
};

int baad[26];

int main()
{
    string s;
    cin>>s;

    string t;
    cin>>t;

    int k;
    cin>>k;

    trie *root= new trie();

    for( int i=0; i<26; i++ )
        baad[i]= (t[i]=='1')?0:1;

    int ans= 0;
    for( int i=0; i<s.size(); i++ )
    {
        trie *curr= root;
        int cnt= 0;
        for( int j=i; j<s.size(); j++ )
        {
            if( baad[s[j]-'a'] )
                cnt++;

            if(cnt>k)
                break;

            if( !curr->nxt[ s[j]-'a' ] )
            {
                ans++;
                curr->nxt[ s[j]-'a' ]= new trie();
            }
            curr= curr->nxt[s[j]-'a'];
        }
    }

    cout<< ans <<endl;
}
