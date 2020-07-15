#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,t,pos;
    cin>>n>>t;
    string s;
    cin>>s;
    while(t--)
    {
        pos=0;
        while(pos<n)
        {
            if(s[pos]=='B' && s[pos+1]=='G')
            {
                s[pos]='G';
                s[pos+1]='B';

                    pos+=2;
            }
            else
                    pos+=1;

        }
    }
    cout<<s;
}
