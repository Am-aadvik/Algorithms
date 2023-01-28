#include "CommonHeader.h"

#ifdef USACO_JAN23_P2_AIRCOWNDITIONING
READ_INPUT(USACO_JAN23_P2_AIRCOWNDITIONING)
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> cow;
vector<pair<int, pair<int, pair<int, int>>>> cond;
vector<bool> curr;
int temp[1001];

int n, m;
int solve(int i)
{
	if (i == m)
	{
		int cost = 0;
		for (int j = 0; j < m; ++j)
		{
			if (!curr[j])
				continue;
			for (int k = cond[j].second.second.first; k <= cond[j].second.second.second; ++k)
				temp[k] += cond[j].first;
			cost += cond[j].second.first;
		}

		bool ok = 1;
		for (int j = 0; j < n; ++j)
			for (int k = cow[j].second.first; k <= cow[j].second.second; ++k)
				if (temp[k] < cow[j].first)
					ok = 0;

		for (int j = 0; j < m; ++j)
		{
			if (!curr[j])
				continue;
			for (int k = cond[j].second.second.first; k <= cond[j].second.second.second; ++k)
				temp[k] -= cond[j].first;
		}

		if (!ok)
			return 10000;
		else
			return cost;
	}

	curr.push_back(0);
	int ans1 = solve(i + 1);
	curr.pop_back();
	curr.push_back(1);
	ans1 = min(ans1, solve(i + 1));
	curr.pop_back();
	return ans1;
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cow.push_back(make_pair(c, make_pair(a, b)));
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cond.push_back(make_pair(c, make_pair(d, make_pair(a, b))));
	}
	cout << solve(0) << endl;
}

#endif
