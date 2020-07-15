#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n=3,a,b,c,arr[3]= {0};
    ll matrix[3][3];
    for(int i=0; i<3; i++)
    {
        cin>>matrix[i][0]>>matrix[i][1]>>matrix[i][2];
            arr[i]+=matrix[i][0];
            arr[i]+=matrix[i][1];
            arr[i]+=matrix[i][2];
    }

    ll low= max( arr[0], max(arr[1],arr[2]) ) + 1;
    ll high= 1e18;
    ll mid=-1, dif1=0, dif2=0, dif3=0;

    for(int i=1;i<=70;i++)
    {
        //cout<<mid<<endl;
        mid= (low+high)/2;
        dif1=mid-arr[0],dif2=mid-arr[1],dif3=mid-arr[2];
        if(dif1+dif2+dif3<mid)
            low=mid+1;
        else
            high=mid-1;

        if(dif1+dif2+dif3==low)
            break;
    }



    dif1=low-arr[0],dif2=low-arr[1],dif3=low-arr[2];
    matrix[0][0]=dif1;
    matrix[1][1]=dif2;
    matrix[2][2]=dif3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<matrix[i][j];
            if(j!=2)
                cout<<" ";
        }
        cout<<endl;
    }


}
