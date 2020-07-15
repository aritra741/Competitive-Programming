#include <iostream>
using namespace std;

int main()
{
    int c,v,v1,a,l,place=0,days=0;
    cin>>c>>v>>v1>>a>>l;
    while(place<c)
    {
        days++;
        place+=v;
        v=min(v1,v+a);
        if(place>=c)
            break;
        place=place-l;
    }
    cout<<days;

}
