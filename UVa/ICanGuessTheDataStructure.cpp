#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        queue <int> q;
        priority_queue<int>pq;
        stack<int>st;
        bool qb,pqb,stb;
        qb=pqb=stb=true;
        for(int i=0;i<n;i++){

        int a,b;
        cin>>a>>b;

        if(a==1)
        {
            if(qb)
            q.push(b);
            if(pqb)
            pq.push(b);
            if(stb)
            st.push(b);
        }
        else if(a==2)
        {
            if(qb)
            {
                if(!q.empty() && q.front()==b)
                    q.pop();
                else
                    qb=false;
            }
            if(pqb)
            {
                if(!pq.empty() && pq.top()==b)
                    pq.pop();
                else
                    pqb=false;
            }
            if(stb)
            {
                if(!st.empty() && st.top()==b)
                    st.pop();
                else
                    stb=false;
            }




        }


        }
        if(qb && !pqb && !stb)
                cout<<"queue"<<endl;
            else if(pqb && !qb && !stb)
                cout<<"priority queue"<<endl;
            else if(stb && !pqb && !qb)
                cout<<"stack"<<endl;
            else if(qb || pqb || stb)
                cout<<"not sure"<<endl;
            else
                cout<<"impossible"<<endl;

    }
}
