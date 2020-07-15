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

struct tri
{
    double x,y;
}triarr[10][3];



double dist( circ p, double x, double y)
{
    return sqrt( (p.x-x)*(p.x-x)+(p.y-y)*(p.y-y) );
}

int sign( tri p, tri q, double x, double y )
{
    double val= (q.y-p.y)*(x-q.x)-
             (q.x-p.x)*(y-q.y);

    val=-val;                   ///In order to harmonize with the convention

    if(val<0)                   ///Clockwise
        return 1;
    else if(val>0)              ///Counter clockwise
        return 2;
    return 0;                   ///Co-linear
}

int pos[11];

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

        else if(s=="c")
        {
            cin>>circarr[cnt].x>>circarr[cnt].y>>circarr[cnt].r;
            pos[cnt++]= 0;
        }

        else
        {
            cin>>triarr[cnt][0].x>>triarr[cnt][0].y
            >>triarr[cnt][1].x>>triarr[cnt][1].y
            >>triarr[cnt][2].x>>triarr[cnt][2].y;
            pos[cnt++]= 2;
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
            if(pos[i]==1)
            {
                if(x>rectarr[i][0].x and x<rectarr[i][1].x and y<rectarr[i][0].y and y>rectarr[i][1].y )
                {
                    cout<<"Point "<<pt<<" is contained in figure "<<i+1<<endl;
                    invalid= 0;
                }
            }

            else if(pos[i]==0)
            {
                if( dist( circarr[i],x,y )<circarr[i].r )
                {
                    cout<<"Point "<<pt<<" is contained in figure "<<i+1<<endl;
                    invalid= 0;
                }
            }

            else
            {
                int val1= sign( triarr[i][0], triarr[i][1], x, y );
                int val2= sign( triarr[i][1], triarr[i][2], x, y );
                int val3= sign( triarr[i][2], triarr[i][0], x, y );

                if(val1==val2 and val2==val3)
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

