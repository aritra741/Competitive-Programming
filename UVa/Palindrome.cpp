#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <char, char> ch;
    char Q=100;
    for(char c='A';c<='Z';c++,Q++)
        ch[c]=Q;
    ch['A']='A';
    ch['E']='3';
    ch['H']='H';
    ch['I']='I';
    ch['J']='L';
    ch['L']='J';
    ch['M']='M';
    ch['O']='O';
    ch['S']='2';
    ch['T']='T';
    ch['U']='U';
    ch['V']='V';
    ch['W']='W';
    ch['X']='X';
    ch['Y']='Y';
    ch['Z']='5';
    ch['1']='1';
    ch['2']='S';
    ch['3']='E';
    ch['5']='Z';
    ch['8']='8';
    string s;
    int q=0;
    int flag=0;
    while(getline(cin, s))
    {
        q=0;
        flag=0;
        for(;q<(s.length()/2);q++)
            if(s[q]!=s[s.length()-1-q])
                flag=1;

        if(flag==0)
        {
            for(q=0;q<(s.length()/2);q++)
            if(ch[s[q]]!=s[s.length()-1-q])
                    flag=2;
            if(s.length()%2==0)
            {if(flag==2)
                cout<<s<<" -- is a regular palindrome."<<endl;
            else cout<<s<<" -- is a mirrored palindrome."<<endl;}
            else {
                if(flag==2)
                cout<<s<<" -- is a regular palindrome."<<endl;
            else
                {
                  if(ch[s[(s.length())/2]]==s[(s.length())/2])
                            cout<<s<<" -- is a mirrored palindrome."<<endl;
                  else cout<<s<<" -- is a regular palindrome."<<endl;
            }}
        }
        else
        {
for(q=0;q<(s.length()/2);q++)
            if(ch[s[q]]!=s[s.length()-1-q])
                    flag=3;

if(flag==3)
    cout<<s<<" -- is not a palindrome."<<endl;
else
    cout<<s<<" -- is a mirrored string."<<endl;

        }
cout<<endl;
    }

}
