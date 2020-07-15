#include <bits/stdc++.h>
using namespace std;
map <char, int> mp;
int main()
{
    int arr[1051];
    memset(arr, 0, sizeof(arr));
    arr[1]=0;
    arr[0]=1;
    for(int i=2;i<=1050;i++)
        for(int j=1;i*j<=1050;j++)
            if(arr[i*j]==0 && j!=1)
                arr[i*j]=1;
    int x=1;

    for(char i='a';i<='z';i++)
    {
        mp[i]=x++;
    }
    for(char i='A';i<='Z';i++)
    {
        mp[i]=x++;
    }
    string s;
   while(getline(cin,s))
   {
        int len=s.length();
        int sum=0;
        for(int i=0;i<len;i++)
            sum+=mp[s[i]];
        if(arr[sum]==1)
            cout<<"It is not a prime word."<<endl;
        else
            cout<<"It is a prime word."<<endl;

   }
}
