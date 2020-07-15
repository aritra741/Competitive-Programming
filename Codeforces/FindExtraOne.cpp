#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
}arr[100007];

int pos, neg;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        {
            cin>>arr[i].x>>arr[i].y;
            if(arr[i].x>0)
                pos++;
            else
                neg++;
        }

    if(pos<2 or neg<2)
        cout<<"Yes";
    else
        cout<<"No";


}
