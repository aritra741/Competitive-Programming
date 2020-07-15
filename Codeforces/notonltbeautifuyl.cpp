#include <bits/stdc++.h>
using namespace std;
int main()
{
    set <char> st;
    map <char, int> mp;
    int o=-1,t=-1,t1=-1;
    for(char i='a'; i<='z'; i++)
        mp[i]=0;
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        st.insert(s[i]);
        mp[s[i]]++;
    }
    if(st.size()>4)
    {
        cout<<"No";
        return 0;
    }
    if(st.size()==4)
    {
        cout<<"Yes";
        return 0;
    }
    if(st.size()==1)
        cout<<"No";
    else if(st.size()==2)
    {
        o=0,t=0;
        for(char i='a'; i<='z'; i++)
        {
            if(mp[i]==1)
                o++;
            else if(mp[i]>1)
                t++;

        }
        if(o==1 && t==1)
            cout<<"No";
        else if(o==2)
            cout<<"No";
        else if(t>=2)
            cout<<"Yes";
    }
    else if(st.size()==3)
    {
        o=0,t=0;
        for(char i='a'; i<='z'; i++)
        {
            if(mp[i]==1)
                o++;
            else if(mp[i]==2)
                t++;
            else if(mp[i]>2)
                t1++;
        }
        if(o==3)
            cout<<"No";
        else
            cout<<"Yes";

    }

}
