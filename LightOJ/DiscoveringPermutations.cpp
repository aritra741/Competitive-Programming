#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){

    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Case %d:\n",i);
    int n,k;
    scanf("%d %d", &n, &k);
    int cnt=1;
    for(int j=0;j<n;j++)
        cout<<s[j];
    cout<<endl;
    while(next_permutation(s.begin(), s.begin()+n))
    {
       if(cnt==k)
        break;
        for(int j=0;j<n;j++)
        cout<<s[j];
       cout<<endl;
       cnt++;


    }

    }
}
