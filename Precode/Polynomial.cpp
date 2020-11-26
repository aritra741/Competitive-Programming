#include <bits/stdc++.h>
using namespace std;

void pol(int i, int n)
{
    if(n==0)
    return;
    if(n==1)
    {
        printf("+ x ");
            return;
    }
    if(i>=n)
        return;
    if(i==1)
    {
        printf("+ x ");
        pol(i+1, n);
    }
    else
    {
        printf("+ x^%d ", i);
        pol(i+1, n);
    }
}
int main()
{
    int n;
    cin>>n;
    printf("1 ");
    pol(1, n);

}
