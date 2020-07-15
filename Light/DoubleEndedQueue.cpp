#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        printf("Case %d:\n", i);
        deque <int> DQ;
        int n,m;
        scanf("%d %d", &n, &m);
        int cnt=0;
        for(int j=0;j<m;j++)
        {
        int val;
        string s;
        cin>>s;
        if(s=="pushLeft")
            {
                scanf("%d", &val);
                if(cnt==n)
                    {
                        printf("The queue is full\n");
                        continue;
                    }
                DQ.push_front(val);

                printf("Pushed in left: %d\n", val);
                cnt++;
            }
        else if(s=="pushRight")
            {
                scanf("%d", &val);
                if(cnt==n)
                    {
                        printf("The queue is full\n");
                        continue;
                    }
                DQ.push_back(val);
                printf("Pushed in right: %d\n", val);
                cnt++;
            }
        else if(s=="popLeft")
            {
                if(cnt==0)
                    {
                        printf("The queue is empty\n");
                        continue;
                    }

                printf("Popped from left: %d\n", DQ.front());
                DQ.pop_front();
                cnt--;
            }
        else
            {
                if(cnt==0)
                    {
                        printf("The queue is empty\n");
                        continue;
                    }

                printf("Popped from right: %d\n", DQ.back());DQ.pop_back();
                cnt--;
            }


        }
    }
}
