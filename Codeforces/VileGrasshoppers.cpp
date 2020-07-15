#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{

    long long int flag=0,p,y;
    cin>>p>>y;
    if(p==y)
        cout<<"-1";
    else
    {
        for(int rev=y; rev>p; rev--)
        {
            int sq=sqrt(rev)+1;
            for(int cou=2; cou<=sq && cou<=p; cou++)
            {
                flag=0;

                if(rev%cou==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<rev;
                break;
            }
        }


        if(flag)
            cout<<"-1";
    }
    return 0;
}



