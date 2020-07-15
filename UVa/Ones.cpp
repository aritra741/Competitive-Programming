#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int i=0;
        int rem= 0;

        for(;;i++)
        {
            int num= rem*10+1;
            rem=num%n;

            if(!rem)
                break;
        }

        cout<< i+1 <<endl;
    }
}
