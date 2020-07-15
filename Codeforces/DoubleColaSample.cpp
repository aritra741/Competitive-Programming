#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
map < int, string > people;
int main()
{
    int n;
    queue <int> q;
    people[1]="Sheldon";
    people[2]="Leonard";
    people[3]="Penny";
    people[4]="Rajesh";
    people[5]="Howard";
    for(int i=1;i<=5;i++)
        q.push(i);
    cin>>n;n--;
    while(n--)
    {
        int u=q.front();
        q.pop();
        q.push(u);
        q.push(u);
    }
    cout<<people[q.front()];

return 0;
}
