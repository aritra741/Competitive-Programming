#include <iostream>
#include <set>
using namespace std;
int main()
{
    set < char > ch;
    char c;
    while(1)
    {

        cin>>c;
        if(c=='}')
            break;
        if(c!='{' & c!=' ' && c!=',')
            ch.insert(c);
    }
    cout<<ch.size();
}
