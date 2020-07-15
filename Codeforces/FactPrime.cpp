#include <bits/stdc++.h>
using namespace std;
vector <int> prime;
int main()
{
    int temp;
    int vis[101];
    memset(vis, 0, sizeof(vis));
    for(int i=2; i<=97; i++)
        if(vis[i]==0)
        {
            prime.push_back(i);
            for(int j=1; i*j<=100; j++)
                if(vis[i*j]==0)
                    vis[i*j]=1;
        }
    int t;
    scanf("%d", &t);

    for(int i=1;i<=t;i++)
    {
        int num;
        scanf("%d" , &num);
        num=factorial[num];
        for(int i=0;i<prime.size();i++)
        {

             int cnt=0;
             temp=prime[i];
            if(num%temp==0)
                {
                    while(temp<=num)
                    {
                        if(num%prime[i]!=0)
                        {
                            if(num!=1)
                            {
                            printf("%d (%d) * ", prime[i],cnt);
                            break;
                            }
                            else
                            {
                            printf("%d (%d)\n", prime[i],cnt);
                            break;
                            }

                        }


                    }
                }
        }

    }


}
