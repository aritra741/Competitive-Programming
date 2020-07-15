#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[181]={0};
    for(double i=3;i<=360;i++)
        if((i-2)*180/i<=180)
            if(floor((i-2)*180/i)==(i-2)*180/i)
                arr[((int)i-2)*180/(int)i]=1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    int ang;
    cin>>ang;
    if(arr[ang]==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
}
