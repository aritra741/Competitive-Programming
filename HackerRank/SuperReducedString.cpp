#include <iostream>
#include <string>

using namespace std;
int main(){
string s;

cin>>s;
int p=s.size();
for(int i=0;i<=(s.size()-2);)
{


    if(s[i+1]==s[i])
        {s.erase(i,2);
            if(i)
                i--;
        }
    else i++;

    if(s.size()==0)
        break;

}
if(s.empty())
    cout<<"Empty String";
else cout<<s;


return 0;}

// pppoippp
