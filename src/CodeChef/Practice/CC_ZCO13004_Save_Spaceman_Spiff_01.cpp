#include "CommonHeader.h"

#ifdef CC_ZCO13004_SAVE_SPACEMAN_SPIFF_01
READ_INPUT(CC_ZCO13004_SAVE_SPACEMAN_SPIFF_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;
#define int int64_t

class Blaster
{
public:
	int x;
	int y;
	int t;
	int f;
};

int n, m, k;


int grid[2501][2501] = { 0, };
Blaster blaster[2501];

bool solve(int i, int j)
{
	if (j == m)
		return 0;

	if (i == n && j == m - 1)
		return 1;

	if (i == n)
		return 0;

	if (grid[i][j] == -1)
		return 0;

	if (grid[i][j] == 1)
		return 1;

	bool r, d;
	r = solve(i, j + 1);
	d = solve(i + 1, j);

	if (r || d)
		return grid[i][j] = 1;

	grid[i][j] = -1;
	return 0;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		cin
			>> blaster[i].x
			>> blaster[i].y
			>> blaster[i].t
			>> blaster[i].f;

		blaster[i].x--;
		blaster[i].y--;

		grid[blaster[i].x][blaster[i].y] = -1;
	}

	int dx[4] = { 0, 0,  1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < k; ++i)
	{
		for (int l = 0; l < 4; ++l)
		{
			int cnt = 1;
			int x = blaster[i].x;
			int y = blaster[i].y;
			int t = blaster[i].t;
			int f = blaster[i].f;

			while (1)
			{
				int x1 = (x + (cnt * dx[l]));
				int y1 = (y + (cnt * dy[l]));

				if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
					break;

				int time = (x1 + y1);
				int dist = (abs(y1 - y) + abs(x1 - x));

				if ((time >= t) && (time - (t + dist)) % f == 0 && (time - ((t + dist)) >= f))
					grid[x1][y1] = -1;

				cnt++;
			}
		}
	}

	bool ans = solve(0, 0);

	cout << (ans ? "YES" : "NO") << endl;

	if (ans)
		cout << (n + m - 2) << endl;

	return 0;
}
#endif
