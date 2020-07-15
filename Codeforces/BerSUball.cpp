#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int counter=0;

    int boys[101];
    int girls[101];

    int n,m,boy,girl;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>boy;
     boys[i]=boy;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>girl;

        girls[i]=girl;

    }
sort(boys, boys+n);
sort(girls, girls+m);
   for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(boys[i]==(girls[j]+1) || boys[i]==(girls[j]-1) || boys[i]==(girls[j]))
            {   girls[j]=-1;
            counter++;
                break;}

cout<<counter;
return 0;
}

