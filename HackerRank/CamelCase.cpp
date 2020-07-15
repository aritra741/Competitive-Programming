#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cou=1;
    string ch;
    cin>>ch;
    int p=ch.size();
    for(int i=0;i<p;i++)
    {
        if(isupper(ch[i]))
            cou++;
    }
    cout<<cou;
    return 0;
}
