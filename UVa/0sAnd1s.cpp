#include <bits/stdc++.h>
using namespace std;
int main()
{

    int tc,q,p,l,mx,mn;
    string s;
    int i=1;
    while(cin>>s)
    {
            scanf("%d", &q);
            printf("Case %d:\n", i++);
            while(q--)
            {
                int flag=0;
                scanf("%d %d", &p, &l);
                mx=max(p,l);
                mn=min(p,l);

                for(int i=mn; i<mx; i++)
                   if(s[i]!=s[i+1])
                        {
                        flag=1;
                        break;
                        }

                if(flag==1)
                    printf("No\n");
                else
                    printf("Yes\n");

            }

        }
    }

