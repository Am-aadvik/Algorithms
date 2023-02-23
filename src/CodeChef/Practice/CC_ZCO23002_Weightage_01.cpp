#include "CommonHeader.h"

#ifndef CC_ZCO23002_WEIGHTAGE_01
READ_INPUT(CC_ZCO23002_WEIGHTAGE_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 
#include<math.h>
using namespace std;
#define int long long
#define float double

vector<pair<int, int>> v, v1;
bool done[200001], ok[9000][9000], ever[9000][9000];
int ans[200001], a[9000][9000];

int32_t main()
{
	int n, p, cnt = 0;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		pair<int, int> p1; cin >> p1.first >> p1.second;v.push_back(p1);
		if (p <= 90) if (!ok[p1.first][p1.second]) 
			ok[p1.first][p1.second] = 1, v1.push_back(p1);
	}

	if (n <= 9000 || p <= 90)
	{
		int mx = (p <= 90 ? v1.size() : n);
		for (int i = 0; i < mx; ++i)
		{
			float low = (int)-1e17, hi = (int)1e17;
			for (int j = 0; j < n; ++j)
			{
				int a1, a2,b1,b2;
				if(p <= 90)
					a1 = v1[i].first, a2 = v1[j].first, b1 = v1[i].second, b2 = v1[j].second;
				else
					a1 = v[i].first, a2 = v[j].first, b1 = v[i].second, b2 = v[j].second;
				if (a1 >= a2 && b1 >= b2) low = max(low, 0.0), hi = min(hi, 100.0);
				else if (a1 < a2 && b1 < b2) { low = -1; break; }
				else if (a2 > a1 && b1 >= b2)
				{
					float x = a2 - a1, y = b1 - b2;
					float d = (50.0 - (((x * 50.0) - (y * 50.0)) / (x + y)));
					low = fmax(low, 0.0), hi = fmin(hi, d);
				}
				else if (a1 >= a2 && b1 < b2)
				{
					float x = a1 - a2, y = b2 - b1;
					float d = (50.0 - (((x * 50.0) - (y * 50.0)) / (x + y)));
					low = fmax(low, d), hi = fmin(hi, 100.0);
				}
			}

			if (p <= 90 && hi <= 100.0 && low >= 0.0 && hi >= low) ever[v1[i].first][v1[i].second] = 1;
			if (hi <= 100.0 && low >= 0.0 && hi >= low) done[i] = 1, cnt++;
		}
	}
	else
	{
		for (int r = 0; r <= 100; r++)
		{
			int max1 = -1e9;
			for (int i = 0; i < n; ++i)
			{
				int curr = ((v[i].first * r) + (v[i].second * (100.0 - r)));
				ans[i] = curr;
				max1 = max(max1, curr);
			}
			for (int i = 0; i < n; ++i)
				if (ans[i] == max1 && done[i] == 0)
					done[i] = 1, cnt++;
		}
	}

	cout << cnt << endl;
	if (p <= 90)
		for (int i = 0; i < n; ++i)
			if (ever[v[i].first][v[i].second])
				cout << (i + 1) << " ";
	else
	for (int i = 0; i < n; ++i)
		if (done[i])
			cout << (i + 1) << " ";
	cout << endl;
}
#endif
