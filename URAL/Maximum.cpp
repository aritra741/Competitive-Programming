#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX];
int mx[MAX];
void PreCal(void)
{
    int MX=1;
    arr[0]=0;
    arr[1]=1;
    mx[0]=0;
    mx[1]=1;
    for(int i=2; i<MAX; i++)
    {
        if(i%2==0)
        {
            arr[i]=arr[i/2];
            mx[i]=max(mx[i-1], arr[i]);
            //cout<<MX<<endl;
        }
        else
        {
            arr[i]=arr[(i-1)/2]+arr[((i-1)/2)+1];
            mx[i]=max(mx[i-1], arr[i]);
            //cout<<MX<<endl;
        }


    }
}


int main()
{
    int n;
    PreCal();
    while(1)
    {
        cin>>n;
        if(n==0)
            return 0;
        cout<<mx[n]<<endl;
    }
}
