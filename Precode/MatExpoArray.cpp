struct matrix
{
    int mat[31][31];
    int row,col;

    matrix()
    {
//        memset(mat,0,sizeof mat);
    }
    matrix(int a, int b)
    {
        row=a,col=b;
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
                for (int k = 0; k <col;  k++)
                {
                    sum += ((mat[i][k]) * (p.mat[k][j]));
                    sum%=MOD;
                }
                temp.mat[i][j] = sum;
            }
        }
        return temp;
    }
    matrix operator+ (const matrix &p) const
    {
        assert(row==p.row && col==p.col);
        matrix temp;
        temp.row=row;
        temp.col=col;
        for(int i=0; i<temp.row; i++)
        {
            for(int j=0; j<temp.col; j++)
                temp.mat[i][j]=((mat[i][j])+(p.mat[i][j]))%MOD;
        }
        return temp;
    }

    matrix identity()
    {
        matrix temp;
        temp.row=row;
        temp.col=col;
        ms(temp.mat,0);

        for(int i=0; i<row; i++)
            temp.mat[i][i]=1;
        return temp;
    }

    matrix pow(ll p, matrix a)
    {
        matrix ret(a.row,a.col);
        ret=ret.identity();
        while(p)
        {
            if(p&1)ret=ret*a;
            a=a*a;
            p>>=1;
        }
        return ret;
    }

    void show()
    {
//        printf("-----------------------------\n");
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                printf("%d ",mat[i][j]);
            printf("\n");
        }
//        printf("-----------------------------\n");
    }

};