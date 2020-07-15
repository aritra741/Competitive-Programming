#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while( scanf("%d", &n)==1 and n )
    {
        if( (n+1)&n )
            printf("Alice\n");
        else
            printf("Bob\n");
    }
}
