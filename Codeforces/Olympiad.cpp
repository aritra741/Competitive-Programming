#include <iostream>
#include <set>
using namespace std;
set < int, greater <int> > things;
int main()
{
    int n,p;cin>>n;
    while(n--)
    {
        cin>>p;
        if(p!=0)
        things.insert(p);
    }
    cout<<things.size();
    return 0;
}
