#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4];
    for(int i=0;i<4;i++)
        cin>>arr[i];

    sort(arr, arr+4);

    int sum[6];
    sum[0]=arr[0]+arr[1];
    sum[1]=arr[0]+arr[2];
    sum[2]=arr[0]+arr[3];
    sum[3]=arr[1]+arr[2];
    sum[4]=arr[1]+arr[3];
    sum[5]=arr[2]+arr[3];

    bool tri=0, seg=0;

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(sum[i]==arr[j])
                seg=1;
            else if(sum[i]>arr[j])
            {
                if(i<=2)
                {
                    int k=i+1;
                    if(k!=j and j!=0 and arr[j]+arr[0]> arr[k] and arr[j]+arr[k]>arr[0])
                        tri=1;
                }

                else
                {
                    int k;
                    if(i<=4)
                        {

                            k=i-1;
                            if(k!=j and j!=1 and arr[j]+arr[k]>arr[1] and arr[j]+arr[1]>arr[k])
                             tri=1;
                        }
                    else
                        if(j!=2 and j!=3 and arr[2]+arr[j]>arr[3] and arr[j]+arr[3]>arr[2])
                            tri=1;
                }



        }
    }
    }
    if(tri)
        cout<<"TRIANGLE"<<endl;
    else if(seg)
        cout<<"SEGMENT"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;

}
