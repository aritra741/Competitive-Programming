#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n+5];
for(int i=0;i<n;i++)  cin>>arr[i];
int ans=0, fin=0;
for(int i=0;i<2*n;i++){
if(arr[i%n]==1) { ans++;
fin=max(ans,fin);
}
else {
    ans=0;
}
}
cout<<fin<<endl;
return 0;
}
