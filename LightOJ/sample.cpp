#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 20005
#define MOD 20071027

using namespace std;

list<int> adj[SIZE];
int color[SIZE];

enum {NOT_VISITED, BLACK, RED};

int main()
{
	int tc, t = 0, i, j, k, m, n, mx = 0, x, y, q, value, node;
	char ch;
	long long sum = 0;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);

	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);

		memset(color, 0, sizeof color);
		for(i = 0; i < SIZE; i++)
			adj[i].clear();

		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		mx = 0;

		for(i = 0; i < SIZE; i++)
		{
			if(!adj[i].empty() && color[i] == NOT_VISITED)
			{
				int black = 0, red = 0;
				queue<int> q;
				q.push(i);
				color[i] = BLACK;
				black++;

				while(!q.empty())
				{
					node = q.front();
					q.pop();

					for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++)
					{
						if(color[*it] == NOT_VISITED)
						{
							q.push(*it);
							if(color[node] == BLACK)
							{
								color[*it] = RED;
								red++;
							}
							else
							{
								color[*it] = BLACK;
								black++;
							}
						}
					}
				}
				mx += max(red, black);
			}
		}

		printf("Case %d: %d\n", t, mx);
	}

	return 0;
}
