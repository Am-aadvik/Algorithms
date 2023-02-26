#include "CommonHeader.h"

#ifdef UVA10653_BOMBS_NO_THEY_ARE_MINES
READ_INPUT(UVA10653_BOMBS_NO_THEY_ARE_MINES)
#include <iostream>
#include <queue>
using namespace std;

#define int long long

int nsafe[1001][1001];
int dist[10001][1001];
int d[5] = { +1,-1,+1,-1 };

bool inside(int i, int j, int n, int m)
{
	if (i >= n || i < 0 || j < 0 || j >= m)
		return 0;

	return 1;
}

int bfs(int i, int j, int t1, int t2, int n, int m)
{
	queue<pair<int, int>> q;
	dist[i][j] = 0;
	q.push({ i,j });

	while (!q.empty())
	{
		int f1 = q.front().first;
		int f2 = q.front().second;
		q.pop();

		for (int k = 0; k < 5; ++k)
		{
			int x = f1;
			int y = f2;

			if (k < 2)
				x += d[k];
			else
				y += d[k];

			if (inside(x, y, n, m) && nsafe[x][y] == 0 && dist[x][y] == 1e18)
			{
				dist[x][y] = dist[f1][f2] + 1;
				if (x == t1 && y == t2)
					return dist[x][y];

				q.push({ x, y });
			}
		}
	}
	return -1;
}

int32_t main()
{
	int n, m;
	cin >> n >> m;
	while (n != 0)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				nsafe[i][j] = 0, dist[i][j] = 1e18;

		int rows;
		cin >> rows;
		for (int i = 0; i < rows; ++i)
		{
			int idx, bombs;
			cin >> idx >> bombs;

			for (int j = 0; j < bombs; ++j)
			{
				int val;
				cin >> val;
				nsafe[idx][val] = 1;
			}
		}

		int s1, s2, d1, d2;
		cin >> s1 >> s2 >> d1 >> d2;

		cout << bfs(s1, s2, d1, d2, n, m) << endl;

		cin >> n >> m;
	}
}
#endif
