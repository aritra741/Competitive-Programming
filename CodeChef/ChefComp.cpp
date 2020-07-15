#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,temp;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        priority_queue <int> q1,q2;
        int sumal=0,sumb=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            sumal+=temp;
            q1.push(temp);
        }
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            sumb+=temp;
            q2.push(temp);
        }
        int al=sumal-q1.top();
        int b=sumb-q2.top();

        if(al<b)
            cout<<"Alice"<<endl;
        else if(b<al)
            cout<<"Bob"<<endl;
        else
            cout<<"Draw"<<endl;
    }
}
