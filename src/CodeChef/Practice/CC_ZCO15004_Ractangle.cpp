#include "CommonHeader.h"

#ifdef CC_ZCO15004_RACTANGLE
READ_INPUT(CC_ZCO15004_RACTANGLE)
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define int long long
vector<pair<int, int> > y, x;
int min[100000][2];
int l[100000][2], r[100000][2];

int find_area(int i, int j, int k, int l)
{
	return ((k - i) * (l - j));
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first != p2.first)
		return p1.first < p2.first;

	return p2.second < p1.second;
}

int max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		pair<int, int> curr;
		cin >> curr.first >> curr.second;
		x.push_back(make_pair(curr.first, curr.second));
		y.push_back(make_pair(curr.second, curr.first));
	}

	sort(y.begin(), y.end());
	sort(x.begin(), x.end());

	int case1 = find_area(0, 0, y[0].first, 100000);
	int max_diff = x[0].first;
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
		{
			if ((100000 - x[i].first) > max_diff)
				max_diff = (100000 - x[i].first);
			continue;
		}

		if ((x[i + 1].first - x[i].first) > max_diff)
			max_diff = (x[i + 1].first - x[i].first);
	}
	int case2 = max_diff * 500;

	stack<int> s1, s2;
	for (int i = 0; i < n; ++i)
	{
		while (!s1.empty() && x[s1.top()].second >= x[i].second)
			s1.pop();

		if (s1.empty())
			l[i][0] = 0, l[i][1] = 0, s1.push(i);
		else
			l[i][0] = x[s1.top()].first, l[i][1] = x[s1.top()].second, s1.push(i);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		while (!s2.empty() && x[s2.top()].second >= x[i].second)
			s2.pop();

		if (s2.empty())
			r[i][0] = 100000, r[i][1] = 0, s2.push(i);
		else
			r[i][0] = x[s2.top()].first, r[i][1] = x[s2.top()].second, s2.push(i);
	}

	int case3 = 0;
	for (int i = 0; i < n; ++i)
		case3 = max(case3, find_area(0, l[i][0], x[i].second, r[i][0]));

	cout << max(case3, max(case1, case2)) << endl;

	return 0;
}
#endif
