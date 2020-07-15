#include <bits/stdc++.h>
using namespace std;
set <int> num;
int main()
{
    long long int a,s,d,f;
    cin>>a>>s>>d>>f;
    num.insert(a);
    num.insert(s);
    num.insert(d);
    num.insert(f);
    cout<<4-num.size();
}
