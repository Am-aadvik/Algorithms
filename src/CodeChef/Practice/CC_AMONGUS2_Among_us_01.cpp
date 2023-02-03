#include "CommonHeader.h"
#define _CRT_SECURE_NO_WARNINGS

#ifdef CC_AMONGUS2_AMONG_US_01
READ_INPUT(CC_AMONGUS2_AMONG_US_01)
#include <iostream>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>> g(500001);
int colour[500001], cnt[2] = { 0, 0 }; bool done = 0;

bool check(int v, int curr)
{
	colour[v] = curr, cnt[curr]++;
	for (int tx = 0; tx < g[v].size(); ++tx)
	{
		int u = g[v][tx].first, t = g[v][tx].second;
		if (colour[u] != -1)
		{
			if ((t == 1 && colour[u] == colour[v]) || (t == 2 && colour[u] != curr))
				return false;
		}
		else
		{
			bool b;
			if (t == 1) b = check(u, curr ^ 1);
			else b = check(u, curr);
			if (!b) return false;
		}
	}
	return true;
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, q; done = 0;
		cin >> n >> q;
		for (int i = 1; i <= n; i++) { g[i].clear(); colour[i] = -1; }
		for (int colour = 0; colour < q; colour++) { int t, u, v; cin >> t >> u >> v; g[u].push_back({ v, t }); g[v].push_back({ u, t }); }

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (colour[i] == -1)
			{
				cnt[0] = cnt[1] = 0;
				if (!check(i, 0)) { cout << -1 << endl; done = 1; continue; }
				ans += max(cnt[0], cnt[1]);
			}
		}

		if (!done)
			cout << ans << endl;
	}
}
#endif