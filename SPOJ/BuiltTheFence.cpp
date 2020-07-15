#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y, idx;
}p[100007];

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        for(int i=0;i<n;i++)
            {
                scanf("%d %d", &p[i].x, &p[i].y);
                p[i].idx= i+1;
            }


    }
}
