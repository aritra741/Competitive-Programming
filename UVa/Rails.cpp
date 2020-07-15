#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1){
    int n;
    cin>>n;
    if(n==0)
        break;
    while(1){
        stack<int> st;
        int t;
        int cnt=0;
        bool flag=0;
        for(int i=0;i<n;i++)
            {
                cin>>t;
                if(t==0)
                    {
                        flag=1;
                        break;
                    }
                while(cnt<n && cnt!=t)
                {
                    if(st.size()>0 && st.top()==t)
                        break;
                    cnt++;
                    st.push(cnt);
                }
                if(st.top()==t)
                    st.pop();

            }
            if(flag==1)
                        {
                            cout<<endl;
                            break;
                        }
            if(st.size()==0)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

    }
    }
}
