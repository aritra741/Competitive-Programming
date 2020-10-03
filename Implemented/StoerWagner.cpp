// Global Min-Cut

const int maxn = 550;
const int inf = 1000000000;
int n, r;
int edge[maxn][maxn], dist[maxn];
bool vis[maxn], bin[maxn];
void init()
{
    memset(edge, 0, sizeof(edge));
    memset(bin, false, sizeof(bin));
}
int contract( int &s, int &t )
{
    memset(dist, 0, sizeof(dist));
    memset(vis, false, sizeof(vis));
    int i, j, k, mincut, maxc;
    for(i = 1; i <= n; i++)
    {
        k = -1; maxc = -1;
        for(j = 1; j <= n; j++)if(!bin[j] && !vis[j] && dist[j] > maxc)
        {
            k = j;  maxc = dist[j];
        }
        if(k == -1)return mincut;
        s = t;  t = k;
		mincut = maxc;
        vis[k] = true;
        for(j = 1; j <= n; j++)if(!bin[j] && !vis[j])
            dist[j] += edge[k][j];
    }
    return mincut;
}
int Stoer_Wagner()
{
    int mincut, i, j, s, t, ans;
    for(mincut = inf, i = 1; i < n; i++)
    {
        ans = contract( s, t );
		bin[t] = true;
        if(mincut > ans)mincut = ans;
        if(mincut == 0)return 0;
        for(j = 1; j <= n; j++)if(!bin[j])
            edge[s][j] = (edge[j][s] += edge[j][t]);
    }
    return mincut;
}

