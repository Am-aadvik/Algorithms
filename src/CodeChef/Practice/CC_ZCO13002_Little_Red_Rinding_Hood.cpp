#include "CommonHeader.h"

#ifdef CC_ZCO13002_LITTLE_RED_RINDING_HOOD
READ_INPUT(CC_ZCO13002_LITTLE_RED_RINDING_HOOD)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;
#define int int64_t
#define NEG -1e9

int safe[501][501], change[501][501], dp[501][501];

bool inside(int x, int y, int n)
{
	if (x >= 0 && y >= 0 && x < n && y < n)
		return 1;

	return 0;
}

pair<bool, int> solve(int i, int j, int n, int curr)
{
	if (i == n && j == n - 1)
		return make_pair(1, curr);

	if (j == n)
		return make_pair(0, NEG);

	if (safe[i][j] == 0 || dp[i][j] == NEG)
		return make_pair(0, NEG);

	if (dp[i][j] != 0)
		return make_pair(1, curr + dp[i][j]);

	pair<bool, int> p1, p2;

	p1 = solve(i, j + 1, n, (curr + change[i][j]));
	p2 = solve(i + 1, j, n, (curr + change[i][j]));

	if (p1.first || p2.first)
	{
		dp[i][j] = fmax(p1.second, p2.second) - (curr);
		return make_pair(1, fmax(p1.second, p2.second));
	}

	dp[i][j] = NEG;
	return make_pair(0, NEG);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> change[i][j];//initialize change in berries

	for (int i = 0; i < m; ++i)
	{
		//inintialize safe
		int x, y, k;
		cin >> x >> y >> k;
		x--, y--;

		int dist = 1;
		for (int i = (x - k); i <= x; ++i, dist += 2)
		{
			if (inside(i, y, n))
				safe[i][y] = 1;
			else
				continue;

			for (int j = (y - (dist / 2)); j <= y; ++j)
			{
				if (inside(i, j, n))
					safe[i][j] = 1;
			}

			for (int j = (y + 1); j <= (y + (dist / 2)); ++j)
			{
				if (inside(i, j, n))
					safe[i][j] = 1;
				else
					break;
			}
		}

		dist -= 4;

		for (int i = (x + 1); i <= (x + k); ++i, dist -= 2)
		{
			if (inside(i, y, n))
				safe[i][y] = 1;
			else
				continue;

			for (int j = (y - (dist / 2)); j <= y; ++j)
			{
				if (inside(i, j, n))
					safe[i][j] = 1;
			}
			for (int j = (y + 1); j <= (y + (dist / 2)); ++j)
			{
				if (inside(i, j, n))
					safe[i][j] = 1;
				else
					break;
			}
		}
		/*
		0001000 -> 0
		0011100 -> 1
		0111110 -> 2
		1111111 -> 3
		0111110 -> 4
		0011100 -> 5
		0001000 -> 6
		^^^^^^^
		|||||||
		0123456
		*/
	}

	pair<bool, int> ans = solve(0, 0, n, 0);

	if (ans.first)
		cout << "YES" << endl << ans.second;
	else
		cout << "NO" << endl;

	return 0;
}

#endif
