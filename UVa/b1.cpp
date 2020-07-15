#include <bits/stdc++.h>
using namespace std;

int cnt[200007][30];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    cin>>s;

    for( int i=0; i<n; i++ )
        for( int j=0; j<30; j++ )
        {
            if(i)
                cnt[ i ][j]= cnt[i-1][j]+( s[i]==(j+'a') );
            else
                cnt[ i ][j]= ( s[i]==(j+'a') );
        }

    int q;
    cin>>q;

    while(q--)
    {
        string t;
        vector<int> cnt2(30,0);
        cin>>t;

        for( int i=0; i<t.size(); i++ )
            cnt2[ t[i]-'a' ]++;

        if( t.size()==1 and t[0]==s[0] )
        {
            cout<<"1"<<endl;
            continue;
        }

        int l= 0, h= n-1, mid= (l+h)/2;

        while( h>=l )
        {
            if( h==l+1 )
                break;
            mid= (l+h)/2;

            bool f= 1;

            for( int i=0; i<30; i++ )
                if( cnt[mid][i]<cnt2[i] )
                {
                    f= 0;
                    break;
                }

            if( f )
                h= mid;
            else
                l= mid;
        }

        cout<<h+1<<endl;
    }
}
