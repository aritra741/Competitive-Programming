#include <bits/stdc++.h>
using namespace std;
priority_queue <int, vector <int>, greater <int> > q;
int main()
{
    int n,m,temp;
    cin>>n>>m;
    map <int, int> arr;
    for(int i=1;i<=m;i++)
    {
        cin>>temp;
        arr[temp-1]++;
    }
    for(int i=0;i<n;i++)
    {

        temp=arr[i];
        q.push(temp);
    }
    cout<<q.top();

}
