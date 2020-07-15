#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.length();
    string s1=s,s2=t;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if(s1==s2)
        cout<<"array"<<endl;
    else
    {
        int len=t.length();
        int cnt=0;
        for(int i=0,j=0;i<n and j<len;i++)
        {
            if(s[i]==t[j])
                cnt++,j++;
        }

        if(cnt==len)
            cout<<"automaton"<<endl;
        else
        {
            int cnt=0;
            for(int j=0;j<len;j++)
                for(int i=0;i<n;i++)
                    if(s[i]==t[j]){
                        cnt++;
                        s[i]=0;
                        break;
                    }

            if(cnt==len and n>=len)
                cout<<"both"<<endl;

            else
                cout<<"need tree"<<endl;
        }
    }
}
