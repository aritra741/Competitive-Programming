#include <bits/stdc++.h>
using namespace std;
string tobin(int n)
{
    stringstream ss;
    ss.str()="";
    string r;
    int num;
    while(n!=0)
    {
        int num=n%2;
        n=n/2;
        ss<<num;
    }
    ss>>r;
    reverse(r.begin(), r.end());
    return r;
}

int main()
{
    while(1)
    {
        unsigned long long i;
        cin>>i;
        if(i==0)
            break;
        string q=tobin(i);
        unsigned long long sum=__builtin_popcount(i);

        cout<<"The parity of "<<q<<" is "<<sum<<" (mod 2)."<<endl;
    }
}
