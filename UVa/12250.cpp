#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int tc=1;
    while(getline(cin, s))
    {
        if(s=="#")
            break;
        if(s=="HELLO")
            printf("Case %d: ENGLISH\n", tc++);
        else if(s=="HOLA")
            printf("Case %d: SPANISH\n", tc++);
        else if(s=="HALLO")
            printf("Case %d: GERMAN\n", tc++);
        else if(s=="BONJOUR")
            printf("Case %d: FRENCH\n", tc++);
        else if(s=="CIAO")
            printf("Case %d: ITALIAN\n", tc++);
        else if(s=="ZDRAVSTVUJTE")
            printf("Case %d: RUSSIAN\n", tc++);
        else
            printf("Case %d: UNKNOWN\n", tc++);
    }
}
