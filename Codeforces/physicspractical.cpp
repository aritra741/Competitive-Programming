#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
    for(int i=0;i<n;i++){
        int l=0,h=n-1,mid,num=2*c[i];
        while(l<h){
            mid=(l+h)/2;
            if(c[mid]<num){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }

    }
}
