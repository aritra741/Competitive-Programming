#include <bits/stdc++.h>
#define MAX(a,b,c) max(a, max(b,c) )
#define MIN(a,b,c) min(a, min(b,c) )
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        map <int, string> mp;
        map <int, string> ::iterator it;
        int n;
        cin>>n;
        string names[n];
        int arr[n];
        for(int i=0; i<n; i++)
        {
            string s;
            int l,w,h;
            cin>>s>>l>>w>>h;
            names[i]=s;
            mp[l*w*h]= s;
            arr[i]=l*w*h;
        }
        sort(arr, arr+n);
        if(arr[n-1]> arr[0])
            cout<<"Case "<<t<<": "<<mp[arr[n-1]]<<" took chocolate from "<<mp[arr[0]]<<endl;
        else
            cout<<"Case "<<t<<": no thief"<<endl;
}
}
