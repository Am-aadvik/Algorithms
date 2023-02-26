#include "CommonHeader.h"

#ifdef CC_ZCO15003_COVERING
READ_INPUT(CC_ZCO15003_COVERING)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
#define int long long
using namespace std;

vector<pair<int, int> > v;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
		return p2.first > p1.first;
	return p2.second > p1.second;
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
		int val1, val2;
		cin >> val1 >> val2;
		v.push_back(make_pair(val1, val2));
	}

	sort(v.begin(), v.end(), comp);

	int ans = 1;//min ans is 1
	int prev = v[0].second;

	for (int i = 1; i < n; ++i)
	{
		if (v[i].first > prev)//no intersection
			ans++, prev = v[i].second;//have to increase ans
			//else do nothing as intersection will not increase size
	}

	cout << ans << endl;
	return 0;
}

#endif
