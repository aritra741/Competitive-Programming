#include <iostream>
#include <queue>
#include <vector>
#define INF 1e5
using namespace std;
vector <int> edge[100];
vector <int> cost[100];
pair < int, int > nodes;
priority_queue < pair < int, int > > pq;
void dijkstra(int src)
{
    int d[100];
    memset(d, INF, sizeof(d));


}
int main()
{
    int t,node1,node2,dist;
    cin>>t;
    while(t--)
{
     cin>>node1>>node2>>dist;
     edge[node1].push_back(node2);
     edge[node2].push_back(node1);
     cost[node1][node2]=dist;
     cost[node2][node1]=dist;

}
int src;
cin>>src;
dijkstra(src);
