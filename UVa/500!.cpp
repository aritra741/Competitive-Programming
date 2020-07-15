#include <bits/stdc++.h>
using namespace std;

string multiply(string str1, string str2){
    int sign = 1;
    if (str1[0] == '-') {
       sign = sign * (-1);
       str1.erase(str1.begin());
    }

    if (str2[0] == '-') {
       sign = sign * (-1);
       str2.erase(str2.begin());
    }
    int m=str1.length(),n=str2.length();

    int pos[m+n+1]={0};
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int mul=(str1[i]-'0')*(str2[j]-'0');
            int p1=i+j,p2=i+j+1;
            int sum=abs(mul)+abs(pos[p2]);
            pos[p1]+=sum/10;
            pos[p2]=sum%10;
        }
    }
    string sb;
    for(int i=0;i<m+n;i++)if(!(sb.length()==0 and pos[i]==0))sb+=to_string(pos[i]);
    if(sb.length()==0)return "0";
    if (sign == -1)
        sb.insert(sb.begin(), '-');
    return sb;
}

string ans[1007];

void pre()
{
    ans[0]= "1";

    for(int i=1;i<=1000;i++)
    {
        stringstream ss;
        ss<<i;
        string t;
        ss>>t;
        ans[i]=multiply( t, ans[i-1] );
    }
}


int main()
{
    pre();
    int n;

    while(cin>>n)
    {
        cout<<n<<"!\n";
        cout<< ans[n] <<endl;
    }

}
