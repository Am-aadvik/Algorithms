#include "CommonHeader.h"

#ifdef CC_SYMARRSWAP_SYMMETRIC_SWAPS_01
READ_INPUT(CC_SYMARRSWAP_SYMMETRIC_SWAPS_01)

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <float.h>
#include <queue>
#include <map>
#include <stdio.h>
using namespace std;

#define INF 1e17
#define int long long

vector <pair<int, pair<int, int>>> v, done;
vector<int> dp;

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		m = 2 * n;
		for (int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			v.push_back({ val,{i,0} });
		}
		for (int i = n; i < m; ++i)
		{
			int val;
			cin >> val;
			v.push_back({ val,{i - n,1} });
		}

		sort(v.begin(), v.end());
		done.resize(n + 1);
		dp.resize(m + 1);

		int ans = 1e17, j = 0;
		for (int i = 0; i < m; ++i)
		{
			if (i) 
				dp[i] = dp[i - 1]; 

			if (done[v[i].second.first].second.first)
				done[v[i].second.first].second.second = 1;
			else
				dp[i]++, done[v[i].second.first].second.first = 1;

			if (dp[i] == n)
			{
				while (done[v[j].second.first].second.second && j < i) done[v[j].second.first].second.second = 0, j++;
				ans = min(ans, (v[i].first - v[j].first));
			}
		}

		cout << ans << endl;
		v.clear();
		done.clear();
		dp.clear();
	}
	return 0;
}

#endif
