#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    int sz=v.size();
}
