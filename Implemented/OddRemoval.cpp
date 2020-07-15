#include <bits/stdc++.h>
using namespace std;
void removeOdd(int i, int j, int *n, int *a)
{
    if(i==*n)
    {   *n=j;
        return;}
    if(a[i]%2==0)a[j++]=a[i];
    removeOdd(i+1,j,n, a);
}
int main()
{
    int i, n, a[100];
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    removeOdd(0,0,&n, a);
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}
