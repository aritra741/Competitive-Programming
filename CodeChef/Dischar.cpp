#include <bits/stdc++.h>
using namespace std;
int main()
{
 int tc;
 cin>>tc;
 while(tc--)
 {
     string s;
     cin>>s;
     set <char> ch(s.begin(), s.end());
     cout<<ch.size()<<endl;

 }
}
