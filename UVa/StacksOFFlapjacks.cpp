#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while(getline(cin,s))
    {
        stringstream ss;
        ss.str()="";
        ss<<s;
        int j=0;
        vector <int> v;
        int t;
        while(ss>>t )
            v.push_back(t);

        j=v.size();
        int st=-1;
        int cnt =0;

        while( cnt<=5 and !is_sorted(v.begin(), v.end()) )
        {
            for(int i=j-1;i>0;i--)
                if(v[i]>v[i-1] and st==-1)
                    st=j-i;
            cout<<st<<endl;
            if(st!=-1)
                {
                    reverse( v.rbegin()+st-1, v.rend() );
                    for(int l=0;l<j;l++)
                        cout<<v[l]<<" ";
                }
                cout<<endl;
                cnt++;
            //cout<<st<<" ";
            st=-1;
        }

        cout<<"0"<<endl;
    }
}
