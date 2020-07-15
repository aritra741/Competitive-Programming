#include<bits/stdc++.h>
using namespace std;

int c[10];

int main()
{
    int x;
    cin>>x;

    int mn= 1000000, num= 1;
    int len= 0;

    for( int i=1; i<=9; i++ )
        cin>> c[i], num= (mn>=c[i])?i:num, mn= min( mn, c[i] ), len= max( len, x/c[i] );

    string ans;

    for( int i=0;i<len;i++ )
        ans.push_back(num+'0');

    int tot= len*mn;

    for( int i=0;i<len;i++ )
    {
        for( int j=9;j>0;j-- )
            if( tot-mn+c[j]<=x )
            {
                ans[i]= j+'0';
                tot= tot-mn+c[j];
                break;
            }
    }

    if(!ans.size())
        ans+= "-1";

    cout<< ans <<endl;
}
