#include <bits/stdc++.h>
using namespace std;

struct rect
{
    double x,y;
}rectarr[10][2];

struct circ
{
    double x,y,r;
}circarr[10];

double dist( circ p, double x, double y)
{
    return sqrt( (p.x-x)*(p.x-x)+(p.y-y)*(p.y-y) );
}

bool pos[11];

int main()
{
    string s;
    int cnt= 0;
    while(cin>>s and s!="*")
    {
        if( s=="r" )
        {
            cin>>rectarr[cnt][0].x>>rectarr[cnt][0].y
            >>rectarr[cnt][1].x>>rectarr[cnt][1].y;
            pos[cnt++]= 1;
        }

        else
        {
            cin>>circarr[cnt].x>>circarr[cnt].y>>circarr[cnt].r;
            pos[cnt++]= 0;
        }
    }

    double x,y;
    int pt= 0;

    while(cin>>x>>y and (x!=9999.9 and y!=9999.9))
    {
        bool invalid= 1;
        pt++;

        for(int i=0;i<cnt;i++)
        {
            if(pos[i])
            {
                if(x>rectarr[i][0].x and x<rectarr[i][1].x and y<rectarr[i][0].y and y>rectarr[i][1].y )
                {
                    cout<<"Point "<<pt<<" is contained in figure "<<i+1<<endl;
                    invalid= 0;
                }
            }

            else
            {
                if( dist( circarr[i],x,y )<circarr[i].r )
                {
                    cout<<"Point "<<pt<<" is contained in figure "<<i+1<<endl;
                    invalid= 0;
                }
            }
        }

        if(invalid)
            cout<<"Point "<<pt<<" is not contained in any figure\n";
    }
}
