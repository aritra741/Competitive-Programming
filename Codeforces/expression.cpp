#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c,ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8;
cin>>a>>b>>c;
ans1=a*b*c;
ans2=(b+c)*a;
//ans3=(a+c)*b;
ans4=(a+b)*c;
ans5=a+b*c;
//ans6=b+a*c;
ans7=c+a*b;
ans8=a+b+c;
cout<<ans1<<ans2<<ans4<<ans5<<ans7<<ans8<<endl;
if(ans1>=ans2&&ans1>=ans4&&ans1>=ans5&&ans1>=ans7&&ans1>=ans8){

    cout<<ans1;
}
else if (ans2>=ans1&&ans2>=ans4&&ans2>=ans5&&ans2>=ans7&&ans2>=ans8){
    cout<<ans2;
}
//else if (ans3>ans1&&ans3>ans2&&ans3>ans4&&ans3>ans5&&ans3>ans6&&ans3>ans7&&ans3>ans8) cout<<ans3;
else if  (ans4>=ans1&&ans4>=ans2&&ans4>=ans5&&ans4>=ans7&&ans4>=ans8) cout<<ans4;
else if (ans5>=ans1&&ans5>=ans2&&ans5>=ans4&&ans5>=ans7&&ans5>=ans8)  cout<<ans5;
//else if (ans6>ans1&&ans6>ans2&&ans6>ans3&&ans6>ans4&&ans6>ans5&&ans5>ans7&&ans6>ans8)   cout<<ans6;
else if   (ans7>=ans1&&ans7>=ans2&&ans7>=ans4&&ans7>=ans5&&ans7>=ans8)  cout<<ans7;


else cout<<ans8;
return 0;
}


