#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    string t= s;
    reverse(t.begin(),t.end());
    s+=t;

    cout<< s <<endl;

}
