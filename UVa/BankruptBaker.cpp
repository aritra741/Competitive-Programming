#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        vector < pair < int, string > > pv;
        string binder;
        getchar();
        getline(cin, binder);
        transform(binder.begin(), binder.end(), binder.begin(), ::toupper);
        cout<<binder<<endl;
        int m,n,b;
        cin>>m>>n>>b;
        map<string, int> ing;
        for(int j=0;j<m;j++)
        {
            string t;
            int c;
            cin>>t;
            cin>>c;
            ing[t]=c;
        }
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            string rec;
            getchar();
            getline(cin, rec);
            int k;
            cin>>k;
            int sum=0;
            for(int p=0;p<k;p++)
            {
                string req;
                int am;
                cin>>req;
                cin>>am;
                sum+=am*ing[req];

            }
            if(sum<=b)
            {
                cnt++;
                pv.push_back( make_pair( sum, rec ) );
            }
        }
        if(cnt==0)
            cout<<"Too expensive!"<<endl;
        else{
            sort(pv.begin(), pv.end());
            int sz=pv.size();
            for(int h=0;h<sz;h++)
                cout<<pv[h].second<<endl;
        }
        pv.clear();
        ing.clear();
        cout<<endl;
    }
}
