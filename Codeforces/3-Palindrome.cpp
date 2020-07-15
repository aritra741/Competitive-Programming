#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a= 0,b= 0;

    for(int i=0;i<n;i++)
    {
        if(a<2)
        {
            cout<<'a';
            a++;
            if(a==2)
                b= 0;
        }

        else if(b<2)
        {
            a= 2;
            cout<<'b';
            b++;
            if(b==2)
                a= 0;
        }
    }
}
