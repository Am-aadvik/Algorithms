#include "CommonHeader.h"

#ifndef UVA11367_FUEL_TANK
READ_INPUT(UVA11367_FUEL_TANK)

#include <iostream>
#include<queue>
#define int long long
#define INF 1e17
using namespace std;

int g[1001][1001], cost[1001], dist[1001][101];
int32_t main()
{

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 101; ++j)
			g[i][j] = INF;
	for (int i = 0; i < n; ++i)
		cin >> cost[i];
	for (int i = 0; i < m; ++i)
	{ 
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = c;
	}

	int q;
	cin >> q;
	while (q--)
	{
		int s, e, c;
		cin >> c >> s >> e;
		priority_queue<pair<int,pair<int,int>>> q;
		q.push({ 0,{0,s} }); dist[s][0] = 0;
		while (!q.empty())
		{
			pair<int,pair<int,int>> f = q.top(); q.pop();
			if (f.first > dist[f.second.second][f.second.first]) continue;
			for (int i = 0; i < n; ++i)
				if (g[f.second.second][i] != INF)
				{
					if (g[f.second.second][i] < f.second.first)
						q.push({ f.first, {f.second.first - g[f.second.second][i],i} });
					for (int fuel = g[f.second.second][i]; fuel + f.second.first < c; ++fuel)
						if (dist[i][f.second.first] > f.first + g[f.second.second][i])
						{
							dist[i][f.second.first] = f.first + g[f.second.second][i];
							int fuel_next = fuel - g[f.second.second][f.second.first];
							q.push({ dist[i][fuel_next],{i,fuel_next} });
						}
				}
		}

		int ans = INF;
		for (int i = 0; i < 101; ++i)
			ans = min(ans, dist[e][i]);
		if (ans < INF) cout << ans << endl;
		else cout << "impossible" << endl;
	}
}
#endif
