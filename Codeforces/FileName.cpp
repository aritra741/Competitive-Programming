#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int cnt= 0, cons= 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='x')
            cons++;
        else
            cnt= (cons>2)? cnt+cons-2:cnt,
            cons= 0;
    }

    cnt= (cons>2)? cnt+cons-2:cnt;

    cout<< cnt <<endl;
}
