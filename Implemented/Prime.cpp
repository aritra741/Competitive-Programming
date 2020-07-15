#include <bits/stdc++.h>
using namespace std;
void prime(int i,int n)
{
    if(i>sqrt(n))
    {
        printf("PRIME\n");
        return;
    }
    if(n%i==0)
    {
        printf("NOT PRIME\n");
        return;
    }
    else prime(i+1,n);
}
int main()
{
    while(1)
    {
    int n;
    cin>>n;
    prime(2, n);
    }


}
