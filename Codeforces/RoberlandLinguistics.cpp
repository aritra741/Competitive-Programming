#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    vector<string> v;

    for(int i=5; i+2<s.size(); i++)
    {
        string t= s.substr( i, 2 );
        v.push_back(t);

        if(i+3<s.size())
        {
            string t= s.substr( i, 3 );
            v.push_back(t);
        }
    }

    sort( v.begin(), v.end() );

    cout<< v.size() <<endl;

    for(int i=0;i<v.size();i++)
        cout<< v[i] <<endl;
}
