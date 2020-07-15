#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,hh,mm;
    while(1)
    {
        cin>>h>>m>>hh>>mm;
        if(h==0 && m==0 && hh==0 && mm==0)
            break;
        int min1=(h*60)+m;
        int min2=(hh*60)+mm;
        if(min2<min1)
            min2+=1440;
        cout<<min2-min1<<endl;;
    }
}
