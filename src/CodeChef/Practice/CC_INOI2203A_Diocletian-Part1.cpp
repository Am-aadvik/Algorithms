#include "CommonHeader.h"

#ifdef CC_INOI2203A_DIOCLETIAN_PART1
READ_INPUT(CC_INOI2203A_DIOCLETIAN_PART1)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int g[1001][1001];

vector<int> curr(1, 0);
vector<vector<int>> res;
int p = -1, cnt = 0;

void solve(int n, int idx)
{
	if (cnt >= p)
		return;

	if (idx == n)
	{
		int n1 = -1, cnt1 = 0, cnt0 = 0;
		for (int i = 0; i < n; ++i)
		{
			if (curr[i] == 1)
				n1 = i, cnt1++;
			else
				cnt0++;
		}

		bool visited1[1001] = { 0 };
		queue<int> q;
		q.push(0);
		visited1[0] = 1, cnt0--;
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			for (int i = 0; i < n; ++i)
				if (curr[i] == 0 && visited1[i] == 0 && g[top][i] == 1)
					q.push(i), cnt0--, visited1[i] = 1;
		}

		bool visited2[1001] = { 0 };
		q.push(n1);
		visited2[n1] = 1, cnt1--;
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			for (int i = 0; i < n; ++i)
				if (curr[i] && visited2[i] == 0 && g[top][i])
					q.push(i), cnt1--, visited2[i] = 1;
		}

		if (cnt1 || cnt0)
			return;
		cnt++;
		res.push_back(curr);
		return;
	}

	curr.push_back(0);
	solve(n, idx + 1);
	curr.pop_back();
	if (cnt >= p)
		return;
	curr.push_back(1);
	solve(n, idx + 1);
	curr.pop_back();
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m >> p;
	bool task2 = 1, task3 = 1;
	int min1 = 1e8, src = -1;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u - 1][v - 1] = g[v - 1][u - 1] = 1;
	}

	solve(n, 1);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << res[i][j];
		cout << endl;
	}
}

#endif
