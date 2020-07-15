#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q ;
    cin>>q;

    while(q--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        if(s.size()>2)
        {
            cout<<"YES\n2\n";
            cout<<s[0]<<" ";
            for(int i=1;i<s.size();i++)
                cout<<s[i];
            cout<<endl;
        }

        else
        {
            if(s[0]>=s[1])
                cout<<"NO\n";
            else
            {
                cout<<"YES\n2\n";
                cout<<s[0]<<" "<<s[1]<<endl;
            }
        }
    }
}
