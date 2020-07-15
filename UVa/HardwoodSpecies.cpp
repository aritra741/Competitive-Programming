#include <bits/stdc++.h>
using namespace std;
int main()
{
        int tc;
        cin>>tc;
        getchar();
        getchar();
        for(int i=1;i<=tc;i++)
        {
            set <string> st;
            set <string> ::iterator it;
            map <string, int> mp;

            int pop=0;
            string s;
            while(getline(cin, s))
            {
                if(s.compare("")==0)
                    break;
                st.insert(s);
                mp[s]++;
                pop++;
            }
            for(it=st.begin();it!=st.end();it++)
                {
                    double prs=(double)mp[*it]/pop;
                    prs*=100.00;
                    cout<<*it<<" "<<setprecision(4)<<fixed<<prs<<endl;
                }
                if(i!=tc)
                cout<<endl;
                else
                continue;
        }
}
