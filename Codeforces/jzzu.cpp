#include<bits/stdc++.h>
using namespace std;
long long ans[10];
int main(){
long long a,b;
long long n;
cin>>a>>b;
cin>>n;
ans[1]=a,ans[2]=b;
ans[3]=b-a;
ans[4]=-a;
ans[5]=-b;
ans[0]=a-b;
long long fin;
fin=ans[n%6]%1000000007;
if(fin<0) fin = (fin+1000000007)%1000000007;
//else fin= ans[n%6];
cout<<fin<<endl;
return 0;
}
