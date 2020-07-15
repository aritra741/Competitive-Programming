#include <bits/stdc++.h>
#define pii pair<int, int>
#define piii pair<pii, int>
using namespace std;
int main()
{
    priority_queue<piii, vector<piii>, greater<piii> > pq;
    string s;
    int id, per, i;
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#")
            break;
        cin>>id>>per;
        i=per;
        pq.push( piii( pii(per, id) , i) );
    }
    int k;
    cin>>k;
    while(k--)
    {
        cout<<pq.top().first.second<<endl;
        piii temp=pq.top();
        pq.pop();
        temp.first.first+=temp.second;
        pq.push(temp);
    }
}
