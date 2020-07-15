#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    int two=0;
    bool atLeastOneTwo=0;
    vector <int> left,right;
    string s;

    cin>>s;
    int len=s.length();

    for(int i=0; i<len; i++)
    {
            if(s[i]=='0')
            {
                if(!atLeastOneTwo)
                    left.pb(0);
                else
                    right.pb(0);
            }

            else if(s[i]=='1')
                left.pb(1);
            else
            {
                atLeastOneTwo=1;
                right.pb(2);
            }
    }

    sort(left.begin(), left.end());
    int sz=left.size();
    for(int i=0;i<sz;i++)
        cout<<left[i];

    sz=right.size();
    for(int i=0;i<sz;i++)
        cout<<right[i];

    }


