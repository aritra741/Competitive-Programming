#include <bits/stdc++.h>
#define INF 1010
using namespace std;
int main()
{

	int tc;
	cin>>tc;
	for(int i=1;i<=tc;i++)
	{
	    bool flag=0;
		int n;
		scanf("%d", &n);
		int x1,y1,z1,x2,y2,z2;
		int MAXx=0;
		int MAXy=0;
		int MAXz=0;
		int MINx=INF;
		int MINy=INF;
		int MINz=INF;
		for(int j=0;j<n;j++)
		{
			scanf("%d %d %d %d %d %d", &x1,&y1,&z1,&x2,&y2,&z2);
			MAXz=max(MAXz, z1);
			MAXx=max(MAXx, x1);
			MAXy=max(MAXy, y1);
			MINz=min(MINz, z2);
			MINy=min(MINy, y2);
			MINx=min(MINx, x2);
            if(MAXx>=MINx || MAXy>=MINy || MAXz>=MINz)
                flag=1;

		}
		if(flag==1)
            printf("Case %d: 0\n", i);
        else
		printf("Case %d: %d\n", i, abs((MAXy-MINy)*(MAXx-MINx)*(MAXz-MINz)));
	}
}
