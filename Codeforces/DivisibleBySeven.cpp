#include <bits/stdc++.h>
using namespace std;

int freq[15];
string saved[]={"1869","6198","1896","9186","9168","6189","8691"};

int main()
{
    string s;
    cin>>s;

    for( int i=0;i<s.size();i++ )
        freq[ s[i]-'0' ]++;

    freq[1]--;
    freq[6]--;
    freq[8]--;
    freq[9]--;

    int remain= 0;

    for( int i=1;i<=9;i++ )
    {
        while( freq[i] )
        {
            cout<< i;

            remain= remain*10+i;
            remain%= 7;

            freq[i]--;
        }
    }

    cout<< saved[remain];

    while( freq[0] )
        cout<< "0",
        freq[0]--;
}
