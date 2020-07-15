#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n and n)
    {
        int l= log2(n);
        int tmp= 1<<l;
        tmp= n-tmp;

        if(tmp)
            tmp= 2*tmp;
        else
            tmp= n;

        cout<< tmp <<endl;
    }
}
