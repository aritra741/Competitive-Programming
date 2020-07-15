#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    getchar();

    while(tc--)
    {
        string s;
        getline(cin,s);
        stringstream ss;
        ss<<s;

        int arr[100], n=0;
        int ans= 1;

        while(ss>>arr[n++]);

        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n-1;j++)
                ans= max(ans, __gcd(arr[i],arr[j]));

        cout<< ans <<endl;
    }
}
