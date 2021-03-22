#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int mod= 10;

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
		memset(mat, 0, sizeof mat);
	}

	matrix operator*(const matrix &p) const
	{
		// assert(col == p.row);
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
					// sum %= mod;
				}
				temp.mat[i][j] = sum%mod;
			}
		}
		return temp;
	}
	matrix operator+ (const matrix &p) const
	{
		// assert(row == p.row && col == p.col);
		matrix temp;
		temp.row = row;
		temp.col = col;
		for (int i = 0; i < temp.row; i++)
		{
			for (int j = 0; j < temp.col; j++)
			{
				temp.mat[i][j] = ((mat[i][j]) + (p.mat[i][j]));

				if(temp.mat[i][j]>=10)
					temp.mat[i][j]-= 10;
			}
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
				printf("%d", mat[i][j]);
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

matrix rec( matrix a, int k )
{
	if (k == 0)
		return a.identity();
	if (k == 1)
		return a;

	matrix half = pow(a, k / 2);
	half = half + half.identity();

	matrix ans = rec( a, k / 2 );
	ans = ans * half;

	if (k & 1)
		ans = ans + pow(a,k);

	return ans;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for ( int t = 1; t <= tc; t++ )
	{
		int n, m;
		scanf("%d %d", &n, &m);

		matrix a(n, n);

		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
			{
				scanf("%d", &a.mat[i][j]);

				if(a.mat[i][j]==10)
					a.mat[i][j]= 0;
			}

		matrix ans = rec( a, m );

		printf("Case %d:\n", t);

		ans.show();
	}
}