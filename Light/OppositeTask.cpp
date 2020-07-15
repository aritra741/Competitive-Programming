#include <iostream>
using namespace std;
int main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        int a;cin>>a;
        if(a<=10)
            cout<<"0 "<<a<<endl;
        else
            cout<<(a/2)<<" "<<a-(a/2)<<endl;
    }
}
