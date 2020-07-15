#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    unsigned long long int j,p=1,q=1,tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        unsigned long long int c,r;

        cin>>j;
        p=ceil(sqrt(j));
        unsigned long long int dif=j-(p-1)*(p-1);
        if(p%2==0)
        {
            if(dif<=p)
            {
                c=dif;
                r=p;
            }
            else
            {
                c=p;
                r=p-(dif-p);

            }
        }
        else
        {
            if(dif<=p)
            {
                c=p;
                r=dif;
            }
            else
            {
                c=p-(dif-p);
                r=p;
            }
        }
        if(j==1)
        {
            r=1;
            c=1;
        }

        cout<<"Case "<<i<<": "<<c<<" "<<r<<endl;
    }

}
