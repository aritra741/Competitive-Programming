#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
}p[10][2];

int main()
{
    string s;
    int i=0;

    while(cin>>s and s!="*")
    {
        cin>>p[i][0].x>>p[i][0].y
        >>p[i][1].x>>p[i][1].y;
        i++;
    }

    double x, y;
    int cnt= 1;

    while(cin>>x>>y and (x!=9999.9 and y!=9999.9))
    {
        bool inside= 0;
        for(int j=0;j<i;j++)
        {
            if( x>p[j][0].x and x<p[j][1].x and y>p[j][1].y and y<p[j][0].y )
                inside= 1, cout<<"Point "<<cnt<<" is contained in figure "<<j+1<<endl;
        }

        if(!inside)
            cout<<"Point "<<cnt<<" is not contained in any figure\n";

        cnt++;
    }
}
