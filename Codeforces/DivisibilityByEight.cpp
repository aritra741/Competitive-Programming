#include <bits/stdc++.h>
using namespace std;
vector <string> vec;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    stringstream ss;
    string t;
    for(int i=0;i<=125;i++)
    {
        int num=8*i;
        ss<<num;
        ss>>t;
        vec.push_back(t);
        ss=stringstream();
    }
    int sz=vec.size();
    for(int i=0;i<sz;i++)
    {
        int len=vec[i].length();
        int cnt=0;
        int slen=s.length();
        for(int j=0;j<slen;j++)
        {
            if(s[j]==vec[i][cnt])
                cnt++;
            if(cnt==len)
            {
                cout<<"YES"<<endl;
                cout<<vec[i];
                return 0;
            }
        }

    }
    cout<<"NO";


}
