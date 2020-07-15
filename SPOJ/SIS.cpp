#include<bits/stdc++.h>
using namespace std;
int main(){
int n,h,a,b,k;
cin>>n>>h>>a>>b>>k;
int ta,fa,tb,fb;
int ans,now;
for(int i=1;i<=k;i++){
         ans=0;
         now=0;
cin>>ta>>fa>>tb>>fb;
if(ta==tb){
    cout<<abs(fa-fb)<<endl;
    continue;
}
if(fa>=a&&fa<=b){
    cout<<abs(fa-fb)+abs(ta-tb)<<endl;
    continue;
}
if(fa<a) {
       ans =abs(fa-a);
       now=a;
}
if(fa>b) {
        ans=abs(fa-b);
         now=b;
}
ans =ans + abs(ta-tb)+abs(now-fb);
cout<<ans<<endl;

}

return 0;
}
