#include <bits/stdc++.h>
using namespace std;
int sum=1;
void pol(int i, int n, int x)
{
    if(n==0)
    return;
    if(n==1)
    {
        printf("+ x ");
          sum+=x;
            return;
    }
    if(i>=n)
        return;
    if(i==1)
    {
        printf("+ x ");
        sum+=x;
        pol(i+1, n, x);
    }
    else
    {
        printf("+ x^%d ", i);
        sum+=pow(x, i);
        pol(i+1, n, x);
    }
}
int main()
{
    int n, x;
    cin>>x>>n;
    printf("1 ");
    pol(1, n, x);
    cout<<endl<<sum;
}

