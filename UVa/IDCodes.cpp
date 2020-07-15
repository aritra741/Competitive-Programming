#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1){
    string s;
    cin>>s;
    if(s=="#")
        return 0;
    if(next_permutation(s.begin(), s.end()))
        cout<<s<<endl;
    else
        printf("No Successor\n");
    }
}
