#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    char arr[row][col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>arr[i][j];
    int taken=-1, rem=-1;
    bool valid[col];
    memset(valid, 1 , sizeof(valid));
    int cnt=0;

    for(int i=0;i<col;i++)
        {
            bool flag=0;
            for(int j=0;j<row-1;j++)
            {
                if(arr[j][i] > arr[j+1][i])
                {
                    if(taken==-1)
                        {
                            cnt++;
                            valid[i]=0;
                           // cout<<j<<" "<<i<<endl;
                            flag=1;
                            break;
                        }
                    else
                    {
                        for(int t=0;t<i;t++){
                                flag=0;
                            if(valid[t]==1)
                                if(arr[j][t]!=arr[j+1][t])
                                    {
                                       // cout<<j<<" "<<t<<endl;
                                        valid[i]=0;
                                        flag=1;
                                        break;
                                    }
                        }
                        if(flag==0)
                        {
                            valid[i]=1;

                        }
                    }
                }
            }
            if(flag==0)
                {
                    valid[i]=1;
                    taken=i;
                }
        }

    cout<<cnt<<endl;

}
