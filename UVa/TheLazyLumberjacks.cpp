#include <bits/stdc++.h>
using namespace std;

bool valid(int a, int b, int c)
{
    if(a+b<=c)
        return 0;
    if(b+c<=a)
        return 0;
    if(c+a<=b)
        return 0;
    return 1;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if(valid(a,b,c))
            cout<<"OK\n";
        else
            cout<<"Wrong!!\n";
    }
}
