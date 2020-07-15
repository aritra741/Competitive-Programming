#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int cnt= 0;

    for( int i=1;i<=n;i=i+1 )
    {
        int p;
        cin>>p;

        if(p==1)
            cnt= cnt+1;
    }

    if(cnt>0)
        cout<<"HARD\n";
    else
        cout<<"EASY\n";
}
