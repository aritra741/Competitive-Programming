#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

map<pii,string> mp;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int p,q;
        string s;
        cin>>p>>q>>s;

        mp[ pii(p,q) ]= s;
    }

    int q;
    cin>>q;

    while(q--)
    {
        int i,j;
        cin>>i>>j;

        cout<< mp[ pii(i,j) ] <<endl;
    }
}
