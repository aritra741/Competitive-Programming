#include <bits/stdc++.h>
using namespace std;
int main()
{
    int flag=0;
    string s;
    cin>>s;
    long long num,curr;
    stringstream last;
    last<<s[s.length()-1];
    long long int lst;
    last>>lst;

    for(int i=0; i<s.length(); i++)
    {

        stringstream ss;
        ss.str()="";
        ss<<s[i];
        ss>>num;
        if(num%2==0)
        {
            curr=i;
            flag=1;

            if(lst>num)
            {
                flag++;
                swap(s[i], s[s.length()-1]);
                cout<<s;
                break;
            }
        }
    }
    if(flag==1)
    {
        swap(s[curr], s[s.length()-1]);
        cout<<s;

    }

    else if(flag==0)
        cout<<"-1";

}
