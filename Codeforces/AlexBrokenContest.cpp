#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt=0;
    if(s.length()<3)
    {
        cout<<"NO";
        return 0;
    }
    int len=s.length();
    if(len>=3){
    for(int i=0;i<len-2;i++)
        {
            string temp=s.substr(i,3);
            if(temp=="Ann")
                cnt++;
            if(cnt>1)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    if(len>=4){
    for(int i=0;i<len-3;i++)
        {
            if(cnt>1)
            {
                cout<<"NO";
                return 0;
            }
            string temp=s.substr(i,4);
            if(temp=="Olya")
                cnt++;

        }
    }
if(len>=5)
{
    for(int i=0;i<len-4;i++)
        {
            if(cnt>1)
            {
                cout<<"NO";
                return 0;
            }
            string temp=s.substr(i,5);
            if(temp=="Danil" || temp=="Slava")
                cnt++;

        }
}
if(len>=6)
{
     for(int i=0;i<len-5;i++)
        {
            if(cnt>1)
            {
                cout<<"NO";
                return 0;
            }
            string temp=s.substr(i,6);
            if(temp=="Nikita")
                cnt++;

        }
}
    if(cnt!=1)
        cout<<"NO";
    else
        cout<<"YES";
}
