#include <bits/stdc++.h>
#define pii pair <int,int>
#define home first
#define away second

int h[100005];

using namespace std;
int main()
{
    int n;
    cin>>n;
    pii arr[n];

    for(int i=0;i<n;i++)
        {
            cin>>arr[i].home>>arr[i].away;
            h[arr[i].home]++;
        }

    for(int i=0;i<n;i++)
    {
        int u= h[ arr[i].away ];
        cout<< (n-1) +u<<" ";
        cout<< (n-1) -u<<endl;
    }


}
