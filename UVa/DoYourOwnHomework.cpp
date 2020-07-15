#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int com;
        cin>>com;
        while(com--)
        {
            string com1;
            int abl;
            cin>>com1>>abl;
            mp[com1]=abl;
        }
        int d;
        cin>>d;
        string sub;
        cin>>sub;
        cout<<"Case "<<i<<": ";
        if(mp[sub]==0 || mp[sub]>d+5)
            cout<<"Do your own homework!"<<endl;
        else if(mp[sub]<=d && mp[sub])
            cout<<"Yesss"<<endl;
        else if(mp[sub]<=d+5 && mp[sub] && mp[sub]>d)
            cout<<"Late"<<endl;
        else
            cout<<"Do your own homework!"<<endl;
        mp.clear();
    }
}
