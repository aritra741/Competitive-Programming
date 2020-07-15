#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cntA=0,cntB=0,cntC=0;
    int mn=0;
    bool flag=0;
    char init='a';
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]!=init && s[i]!=init+1)
        {
            //cout<<init<<" "<<s[i]<<endl;
            flag=1;
            break;
        }
        if(s[i]=='a')
            cntA++;
        if(s[i]=='b')
            cntB++;
        if(s[i]=='c')
            cntC++;
        init=s[i];
    }
    if(flag==0 && cntA>0 && cntB>0 && (cntC==cntA || cntC==cntB) )
        cout<<"YES";
    else
        cout<<"NO";
}
