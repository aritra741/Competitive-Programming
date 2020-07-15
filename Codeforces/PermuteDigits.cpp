#include <bits/stdc++.h>
using namespace std;

string s,t;

int main()
{
    cin>>s>>t;

    sort( s.begin(), s.end() );
    reverse( s.begin(), s.end() );

    if(s.size()<t.size())
    {
        cout<< s <<endl;

        return 0;
    }

}
