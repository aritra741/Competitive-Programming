#include <bits/stdc++.h>
using namespace std;
  long long ppcnt(  long long n,   long long z) {
  int result = 0;
  while (n != 0) {
    result += ((n%10) == 0);
    n /= 10;
  }
  return result;
}

  long long cnt(  long long n,   long long z)
{
  if (n < 10)
  {if(n==0)
        return 1;
    return 0;}
if ((n % 10) != 9) return ppcnt(n, z) + cnt(n-1, z);

  return 10*cnt(n/10, z) + (n/10);
}
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
    long long n1,n2,ans1;
    scanf("%lld %lld", &n1,&n2);
    if(n1==0)
    ans1=cnt(n1, 0);
    else ans1=cnt(n1-1, 0);
      long long ans2=cnt(n2, 0);
      long long ans=ans2-ans1;
    if(n1==0)
        ans+=2;
    else if(n1==1)
        ans+=1;
    printf("Case %d: %lld\n", i, ans);
}
}
