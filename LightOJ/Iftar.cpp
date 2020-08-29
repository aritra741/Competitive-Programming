#include <bits/stdc++.h>
using namespace std;


int main()
{

    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        priority_queue <int, vector <int>, greater <int> > pq;
        int temp;
        bool flag=0;
        int p,l;
        cin>>p>>l;
        int tar=p-l;
        int sq=sqrt(tar);
//if(tar==0 && l==0)
//    cout<<"Case "<<i++<<": 1"<<endl;
//else
        for(int j=1; j<=sq; j++)
        {
            if(tar%j==0)
                {
                    if(tar/j>l)
                       {
                           flag=1;
                           pq.push(tar/j);
                       }
                    if(j>l && j!=(tar/j))
                    {
                        flag=1;
                        pq.push(j);
                    }
                }


            }
            if(!flag)
            cout<<"Case "<<i<<": impossible";
        else
        {
            cout<<"Case "<<i<<": ";
            while(!pq.empty())
            {
                temp=pq.top();
                pq.pop();
                cout<<temp;
                if(!pq.empty())
                    cout<<" ";

        }
    }
cout<<endl;

}

}
