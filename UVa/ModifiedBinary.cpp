#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s=="0")
            break;
        long long sum=0;
        long long len=s.length();
        reverse(s.begin(),s.end());
        for(long long i=0;i<len;i++)
        {
            sum+=(pow(2, i+1)-1)*(s[i]-'0');
        }
        cout<<sum<<endl;
    }
}
