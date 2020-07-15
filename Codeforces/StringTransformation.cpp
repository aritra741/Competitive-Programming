#include <iostream>
#include <string>
#include <map>
using namespace std;
map < char, int > alpha;
map < int, char > beta;
int main()
{
    int q=1,p=1;
    char l='a';
    string s;
    for(char i='a';i<='z';i++,q++)
        alpha[i]=q;
    for(int i=1;i<=26;i++,l++)
        beta[i]=l;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {

        if(alpha[s[i]]<=p)
        {
            s[i]=beta[p];
            p++;

        }
        if(p==27)
            break;



    }
    if(p==27)
        cout<<s;
    else cout<<"-1";
    return 0;
}
