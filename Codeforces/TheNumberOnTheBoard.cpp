#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;

    int tot= 0;
    int cnt= 0;

    sort( s.begin(), s.end() );

    for(int i=s.size()-1;i>=0;i--)
        tot+= s[i]-'0';

    if(tot>=k)
    {
        cout<<"0\n";
        return 0;
    }

    for(int i=0;i<s.size();i++)
    {
        tot+= '9'-s[i];
        cnt++;

        if(tot>=k)
            break;
    }

    cout<< cnt <<endl;
}
