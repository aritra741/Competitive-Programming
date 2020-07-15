#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    int cnta=0,cntb=0;
    int flag=0;
    int err1=0,err2=0;
    int pos=0;;

    for(int i=0; i<len-1; i++)
    {
        string temp=s.substr(i, 2);
        if(temp=="AB")
        {
            pos=i+2;
            flag=1;
            break;

        }
    }
    if(flag==1)
    {
        for(int i=pos; i<len-1; i++)
        {
            string temp=s.substr(i, 2);
            if(temp=="BA")
            {
                flag=2;
                break;

            }
        }
    }
    if(flag==2)
    {
        cout<<"YES";
        return 0;
    }
    flag=0;
    for(int i=0; i<len-1; i++)
    {
        string temp=s.substr(i, 2);
       // cout<<temp<<endl;
        if(temp=="BA")
        {
            pos=i+2;
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        for(int i=pos; i<len-1; i++)
        {
            string temp=s.substr(i, 2);
            if(temp=="AB")
            {
                flag=2;
                break;
            }
        }
    }
    if(flag==2)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";

}
