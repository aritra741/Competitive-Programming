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

    for(int i=0; i<n-1; i++)
    {

        while(s[i]!=t[i])
        {
            int tar=n;
           // cout<<s<<endl<<t<<endl<<endl;
            for(int j=i+1; j<tar; j++)
            {
                if(s[j-1]!=t[i] and s[j-1]!= s[j])
                {
                    v.push_back(j);
                    swap(s[j-1],s[j]);

                   // cout<<"Ekhon "<<j<<endl;
                }

                else
                {
                    swap(s[j-1],s[j]);
                    v.push_back(j);
                    tar=j;
                    //cout<<"Ekheiughon "<<j<<endl;

                }
            }
        }
    }
int sz=v.size();
    cout<<sz<<endl;
    for(int i=0; i<sz; i++)
        cout<<v[i]<<" ";


}
