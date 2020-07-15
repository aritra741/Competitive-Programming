#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
string s;
cin>>n>>s;
int cont;
if(s[0]=='+')  cont=1;
    if(s[0]=='-')  cont=0;
for(int i=1;i<s.size();i++){

    if(s[i]=='+') ++cont;
    if(s[i]=='-') --cont;
    if(cont<0) cont=0;
   // cout<<cont<<endl;

}
if(cont<0) cout<<0<<endl;
else cout<<cont<<endl;
return 0;
}
