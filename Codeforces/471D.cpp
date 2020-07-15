#include<bits/stdc++.h>
#define mx 400007
using namespace std;

int ap[mx], arr[mx], arr1[mx];
int pre[mx];
int n,w;

void precal()
{
    int q= -1;
    for( int i=1; i<w; i++ )
    {
        while(q>-1 and arr[q+1]>arr[i] and arr[q+1] )
            q= pre[q];

        if( arr[q+1]==arr[i] or !arr[q+1] )
            q++;
        pre[i]= q;
    }
}

int find_occ(int n, int m) //pattern length, text length
{
	int i = 0, j = 0, c = 0;
	while (j < m)
	{
		if (arr[i] == ap[j] or !arr[i])
		{
			i++, j++;
			if (i == w)c++, i = pre[i - 1]+1;
		}
		else
		{
			if (i == 0)j++;
			else i = pre[i - 1]+1;
		}
	}
	return c;
}

int main()
{
    memset( pre, -1, sizeof(pre) );
    scanf("%d %d", &n, &w);

    if(w==1)
        return cout<<n<<endl, 0;

    int prev= -1;

    for( int i=0;i<n;i++ )
    {
        scanf("%d", &ap[i]);

        int tmp= prev;
        prev= ap[i];

        if(i)
            ap[i]-= tmp;
    }

    ap[0]= 0;
    prev= -1;
    for( int i=0;i<w;i++ )
    {
        scanf("%d", &arr[i]);

        int tmp= prev;
        prev= arr[i];

        if(i)
            arr[i]-= tmp;
    }

    arr[0]= 0;

    precal();

    int ans= find_occ( w, n );

    printf("%d\n", ans);
}
