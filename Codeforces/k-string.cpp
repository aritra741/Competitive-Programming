#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[26]={0};
    int n;
    cin>>n;
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
        {
            arr[s[i]-97]++;

        }
    for(int i=0;i<26;i++)
        {
            if(arr[i]%n!=0)
           {
            cout<<-1;
            return 0;
           }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
            for(int k=1;k<=arr[j]/n;k++)
                printf("%c", 97+j);
    }
}
