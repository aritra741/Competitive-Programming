#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
int flag=0;
cin>>s;
for(int i=0;i<s.size();i++){
  if(s.substr(i,3)=="WUB"){

    i=i+2;
    if(flag==1){cout<<" ";}
    continue;
  }

   else {
      cout<<s[i];
      flag=1;

   }

}





return 0;
}
