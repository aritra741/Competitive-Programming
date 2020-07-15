#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> >pq;
vector<int>v;

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0;i<n;i++ )
    {
        int p;
        scanf("%d", &p);

        pq.push(p);
    }

    while(!pq.empty())
    {
        int u= pq.top();
        pq.pop();

        if( pq.empty() or pq.top()!=u )
            v.push_back(u);
        else
        {
            int v= pq.top();
            pq.pop();

            pq.push(u+1);
        }
    }

    printf("%d\n", v.size());
}
