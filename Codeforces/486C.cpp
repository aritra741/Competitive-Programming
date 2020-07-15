#include<bits/stdc++.h>
using namespace std;

int arr[200007];
int n,p;
string s;

int opp( int x )
{
    return n-x-1;
}

int shrt( int x, int y )
{
    return min( abs(y-x), min( n-y+x+1, y+n-x+1 ) );
}

int dist( char a, char b )
{
    return min( abs(a-b), min( 'z'-b+a-'a'+1, b-'a'+'z'-a+1 ) );
}

int main()
{
    cin>>n>>p;

    cin>>s;

    int ans= 0;
    int now= p;

    if(p>n/2)
        reverse( s.begin(), s.end() ), p= n-p+1;

    int en= n/2;

    for( int i= n/2-1; i>=0; i-- )
    {
        if( s[i]==s[n-i-1] )
            en--;
        else
            break;
    }

    int st= 1;

    for( int i=0;i<n/2;i++ )
    {
        if( s[i]==s[n-i-1] )
            st++;
        else
            break;
    }

    st= min( st,p );
    en= max( en,p );

    ans= min( p-st+en-st, en-p+en-st );

    for( int i=0; i<n/2; i++ )
        ans+= dist( s[i], s[opp(i)] );


    cout<<ans<<endl;
}
