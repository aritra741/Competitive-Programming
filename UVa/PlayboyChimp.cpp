#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> arr;
    vector <int> ::iterator l;
    vector <int> ::iterator u;
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    int query;
    cin>>query;
    while(query--)
    {
        int h;
        cin>>h;
        u=lower_bound(arr.begin(), arr.end(), h);
        if(u==arr.begin())
            cout<<"X ";
        else
            cout<<*--u<<" ";
        l=upper_bound(arr.begin(), arr.end(), h);
        if(l==arr.end())
            cout<<"X"<<endl;
        else
            cout<<*l<<endl;
    }

}
