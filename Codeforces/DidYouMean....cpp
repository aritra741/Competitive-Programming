 #include <bits/stdc++.h>
using namespace std;

bool cons( char c )
{
    if( c=='a' or c=='e' or c=='i' or c=='o' or c=='u' )
        return 0;
    return 1;
}

int main()
{
    string s;
    cin>>s;

    set<char> st;
    string now;
    int cnt= 0;

    for(int i=0;i<s.size();i++)
    {
        if( cons(s[i]) )
            cnt++,
            st.insert( s[i] );

        if( cnt>=3 and st.size()>1 )
        {
            st.clear();
            st.insert( s[i] );
            cnt= 1;
            cout<< now <<" ";
            now.clear();
        }

        else if( !cons(s[i]) )
            st.clear(),
            cnt= 0;

        now+= s[i];
    }

    if( now[0]!=0 )
        cout<<now<<endl;
}
