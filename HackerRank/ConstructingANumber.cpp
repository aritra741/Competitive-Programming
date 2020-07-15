#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int q;
    scanf("%d", &q);

    while(q--)
    {

    int n;
    scanf("%d", &n);

    int tot=0;

    while(n--)
    {
        string s;
        cin>>s;
        int len=s.size();

        for(int i=0;i<len;i++)
        {
            tot+= (s[i]-'0')%3;
        }
    }

    tot%=3;

    if(!tot)
        printf("Yes\n");
    else
        printf("No\n");
    }
}
