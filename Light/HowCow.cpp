#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        printf("Case %d:\n", i);
        int x1,y1,x2,y2;
        scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
        int difx=x2-x1;
        int dify=y2-y1;
        int n,p,q;
        cin>>n;
        while(n--)
        {
            scanf("%d %d", &p,&q);
            int difp=x2-p;
            int difq=y2-q;
            if(difp<0 || difq<0 || difp>difx || difq>dify)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
}
