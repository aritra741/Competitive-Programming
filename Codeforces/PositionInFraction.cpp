#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int now= -1, prev= -2, cnt= 0;

    while(now!=c and cnt<1000000)
    {
        cnt++;
        a*=10;
        prev= now;
        now= a/b;
        a= a%b;
    }

    if(now==c)
        cout<< cnt <<endl;
    else
        cout<< "-1" <<endl;
}
