#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string temp1=s,temp2=t;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());

    if(temp1!=temp2)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    vector <int> v;

    for(int i=0;i<n;i++)
    {
        int j=i;
        while(s[j]!=t[i])
            {
                v.push_back(j);
                j++;
            }

    }

    int sz=v.size();
    cout<<sz<<endl;
    for(int i=0; i<sz; i++)
        cout<<v[i]<<" ";
}
