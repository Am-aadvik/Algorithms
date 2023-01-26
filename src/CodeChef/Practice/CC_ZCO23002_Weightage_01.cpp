#include "CommonHeader.h"

#ifdef CC_ZCO23002_WEIGHTAGE_01
READ_INPUT(CC_ZCO23002_WEIGHTAGE_01)
#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;
#define int long long

vector<pair<int, int>> v;
bool done[200001];
int ans[200001];

int32_t main()
{
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	int cnt = 0, rHelper = 0;

	if (n < 1000)
	{
		for (double r = 0.0; r <= 100.0000000000000000001; rHelper++, r = (rHelper / 1000.0))
		{
			int max = -1e9;
			for (int i = 0; i < n; ++i)
			{
				int curr = ((v[i].first * r) + (v[i].second * (100.0 - r)));
				ans[i] = curr;
				max = fmax(max, curr);
			}

			for (int i = 0; i < n; ++i)
				if (ans[i] == max && done[i] == 0)
					done[i] = 1, cnt++;
		}
	}
	else
	{
		for (int r = 0; r <= 100; r++)
		{
			int max = -1e9;
			for (int i = 0; i < n; ++i)
			{
				int curr = ((v[i].first * r) + (v[i].second * (100.0 - r)));
				ans[i] = curr;
				max = fmax(max, curr);
			}

			for (int i = 0; i < n; ++i)
				if (ans[i] == max && done[i] == 0)
					done[i] = 1, cnt++;
		}
	}

	cout << cnt << endl;
	for (int i = 0; i < n; ++i)
		if (done[i])
			cout << (i + 1) << " ";
	cout << endl;
}

#endif
