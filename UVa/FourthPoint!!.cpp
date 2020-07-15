#include <bits/stdc++.h>
#define pdd pair <double, double >
using namespace std;
int main()
{
        pdd points;
        set <pdd> st;
        set <pdd> ::iterator it;
        map<pdd, int> mp;
    double x1,x2,x3,x4,y1,y2,y3,y4;
    while( cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4 )
    {

        st.insert(pdd(x1,y1));
        mp[pdd(x1,y1)]++;
        st.insert(pdd(x2,y2));
        mp[pdd(x2,y2)]++;
        st.insert(pdd(x3,y3));
        mp[pdd(x3,y3)]++;
        st.insert(pdd(x4,y4));
        mp[pdd(x4,y4)]++;
        pdd same;
        for(it=st.begin();it!=st.end();it++)
        {
            if( mp[pdd(it->first, it->second)]==2 )
            {
                same.first=it->first;
                same.second=it->second;
            }

        }
        pdd pts[2];
        int i=0;
        for(it=st.begin();it!=st.end();it++)
        {
            if(i==2)
                break;
            if(mp[pdd(it->first, it->second)]==1)
            {
                pts[i].first=it->first;
                pts[i].second=it->second;
                i++;
            }
        }
//        cout<<setprecision(3)<<fixed<<same.first<<" "<<setprecision(3)<<fixed<<same.second<<endl;
        double x= pts[0].first+pts[1].first-same.first;
        double y= pts[0].second+pts[1].second-same.second;
        cout<<setprecision(3)<<fixed<<x<<" "<<setprecision(3)<<fixed<<y<<endl;
        mp.clear();
        st.clear();
    }
}
