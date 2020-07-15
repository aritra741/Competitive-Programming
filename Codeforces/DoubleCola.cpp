#include <iostream>
#include <map>
#include <string>
#include <math.h>
using namespace std;
map < int, string > people;
int main()
{
    int n,j=0,temp=0;
    double i=0;
    cin>>n;
    people[1]="Sheldon";
    people[2]="Leonard";
    people[3]="Penny";
    people[4]="Rajesh";
    people[5]="Howard";

    while(1)
    {
        j=n-temp;
        temp+=(5*pow(2, i));
        if(temp>=n)
            break;
        i++;
    }

    int p=1;
    int q;
    int thing=(int)pow(2, i);
    q=thing;


    while(p<=5)
    {

        if(j<=q)
            break;
        else
            q+=thing;

        p++;
    }
    cout<<people[p];

    return 0;

}

