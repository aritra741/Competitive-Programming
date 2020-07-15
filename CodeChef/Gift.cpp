#include <stdio.h>
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n,k;
        scanf("%d %d", &n,&k);
        int i=0,temp,cnt=0;
        for(; i<n; i++)
        {
            scanf("%d", &temp);
            if(temp%2==0)
                cnt++;
        }
        if(cnt>=k)
        {
            if(k!=0)
                printf("YES\n");

            else if(cnt<n && k==0)
                printf("YES\n");
            else
                printf("NO\n");

        }
        else
            printf("NO\n");
    }
}
