#include <bits/stdc++.h>
#define ll long long
#define int unsigned int
using namespace std;

int ncr[55][55];

void init()
{
	ncr[0][0]= 1;

	for( int i=1;i<=51;i++ )
	{
		ncr[i][0]= 1;
		for( int j=1;j<=i;j++ )
			ncr[i][j]= ncr[i-1][j]+ncr[i-1][j-1];
	}
}

struct matrix
{
    int mat[55][55];
    int row, col;

    matrix()
    {
//        memset(mat,0,sizeof mat);
    }
    matrix(int a, int b)
    {
        row = a, col = b;
//        memset(mat,0,sizeof mat);
    }

    matrix operator*(const matrix &p) const
    {
        assert(col == p.row);
        matrix temp;
        temp.row = row;
        temp.col = p.col;
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
            {
                int sum = 0;
                for (int k = 0; k < col;  k++)
                {
                    sum += ((mat[i][k]) * (p.mat[k][j]));
                    // sum %= MOD;
                }
                temp.mat[i][j] = sum;
            }
        }
        return temp;
    }
    matrix operator+ (const matrix &p) const
    {
        assert(row == p.row && col == p.col);
        matrix temp;
        temp.row = row;
        temp.col = col;
        for (int i = 0; i < temp.row; i++)
        {
            for (int j = 0; j < temp.col; j++)
                temp.mat[i][j] = ((mat[i][j]) + (p.mat[i][j]));
        }
        return temp;
    }

    matrix identity()
    {
        matrix temp;
        temp.row = row;
        temp.col = col;
        memset(temp.mat, 0, sizeof(temp.mat));

        for (int i = 0; i < row; i++)
            temp.mat[i][i] = 1;
        return temp;
    }

    void show()
    {
//        printf("-----------------------------\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
//        printf("-----------------------------\n");
    }

};

matrix pow(matrix a, ll p)
{
    matrix ret(a.row, a.col);
    ret = ret.identity();
    while (p)
    {
        if (p & 1)ret = (ret * a);
        a = (a * a);
        p >>= 1;
    }
    return ret;
}



int32_t main()
{
	init();

	int tc;
	scanf("%u", &tc);

	for( int t=1;t<=tc;t++ )
	{
		ll n,k;
		scanf("%lld %lld", &n, &k);

		matrix x(k+2,k+2), y(k+2,1);

		for( int i=0;i<=k;i++ )
		{
			for( int j=0;j<=i;j++ )
				x.mat[i][j]= ncr[i][j];
			for( int j=i+1;j<=k+1;j++ )
				x.mat[i][j]= 0;
		}

		for( int i=0;i<=k+1;i++ )
			y.mat[i][0]= 1;
		for( int i=0;i<=k;i++ )
			x.mat[k+1][i]= ncr[k][i];
		x.mat[k+1][k+1]=1;

		matrix ans(k+2,1);
		x= pow(x,n-1);
		ans= x*y;

		printf("Case %u: %u\n", t, ans.mat[k+1][0]);
	}
} 