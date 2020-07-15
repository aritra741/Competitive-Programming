#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1e5+7


int l[]={-1,0,1,0};
int k[]={0,1,0,-1};

int n,m;

void dijkstra(iii s, vector<vi> *dist, vector<vi> *graph){
    priority_queue< iii, vector<iii>, greater<iii> > pq;
    pq.push(s);
    while (!pq.empty()) {
        iii bg = pq.top();           //sort based on cost
        pq.pop();
        int d = bg.first;             //cost
        ii u = bg.second;             //pair of co ordinates
        if(dist->at(u.first)[u.second]<d)
            continue;
        for (int j = 0; j < 4; j++) {
                int x =u.first + l[j];
                int y =u.second + k[j];
                if(x>=0 && x<n && y>=0 && y<m){
                    int v = graph->at(x)[y];
                    if (dist->at(u.first)[u.second] + v < dist->at(x)[y]) {
                        dist->at(x)[y] = dist->at(u.first)[u.second]  + v;
                        ii vec (x,y);
                        pq.push(iii(dist->at(x)[y], vec));
                    }
                }
            }
    }
}

int main(){
    int tc,num;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        scanf("%d",&m);
        vector<vi> G;
        for (int i=0; i<n; ++i)
        {
            vi r;
            for (int j=0; j<m ; ++j)
            {
                scanf("%d",&num);
                r.push_back(num);
            }
            G.push_back(r);
        }
        vi cl(m,INF);
        vector<vi> dist (n,cl);
        dist[0][0] = G[0][0];
        dijkstra(iii(G[0][0],ii(0,0)),&dist,&G);
        printf("%d\n",dist[n-1][m-1]);

    }
 return 0;

}
//d == dist->at(u.first)[u.second]
