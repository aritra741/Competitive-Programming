#include <bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin>>n;

        if(n==0)
            break;

        deque<int> d;

        for(int i=n;i>=1;i--)
            d.push_front(i);

        cout<<"Discarded cards:";

        while(d.size()!=1)
        {
            int u=d.front();
            cout<<" "<<u;
            d.pop_front();
            int v=d.front();
            d.pop_front();
            d.push_back(v);
            if(d.size()!=1)
                cout<<",";
        }

        cout<<endl<<"Remaining card: "<<d.front()<<endl;
    }
}
