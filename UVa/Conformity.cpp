#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
set <string> st;
set <string>:: iterator it;
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
        {
            int arr[5];
            string s="";
            stringstream ss;
            string t;
            for(int j=0; j<5; j++)
            {
                cin>>arr[j];
            }
            sort(arr, arr+5);
            for(int j=0; j<5; j++)
            {
                ss<<arr[j];
                ss>>t;
                s+=t;
                ss=stringstream();
            }
            mp[s]++;
            st.insert(s);

        }
        int mx=0;
        int ans=0;
        for(it=st.begin(); it!=st.end(); it++)
            {
                if(mp[*it]>mx)
                    {
                        mx=mp[*it];
                        ans=mx;
                    }
                else if(mp[*it]==mx)
                        ans+=mx;
            }
        if(mx==1)
            ans=n;
        cout<<ans<<endl;

        st.clear();
        mp.clear();
    }
}
