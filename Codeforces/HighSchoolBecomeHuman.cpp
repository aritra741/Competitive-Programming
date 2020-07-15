#include <bits/stdc++.h>
#define eps 1e-7
using namespace std;

int main()
{
    double x,y;
    cin>>x>>y;

    double x1= y*log10(x);
    double y1= x*log10(y);

    if(fabs(x1-y1)<eps)
        cout<<"=\n";
    else if(x1<y1)
        cout<<"<\n";
    else
        cout<<">\n";
}
