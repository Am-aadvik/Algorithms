#include "CommonHeader.h"
#ifdef CC_ZCO23001_PARCHMENT_01
READ_INPUT(CC_ZCO23001_PARCHMENT_01)
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 
using namespace std;

vector<vector<int>> ans;
int p[2000001];
int up_bnd[1000001];

int compute(int k, int mx, int mn)
{
	int cnt = 0;
	while (mn <= mx)
	{
		mn += k;
		cnt++;
		mn = up_bnd[mn];
	}

	return cnt;
}

int32_t main()
{
	int n, a;
	cin >> n >> a;
	for (int i = 0; i < n; ++i)
		cin >> p[i];

	sort(p, p + n);

	int prev = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = prev + 1; j <= p[i]; ++j)
			up_bnd[j] = p[i];
		prev = p[i];
	}

	for (int i = 0; i < a; ++i)
		ans[compute(i, p[0], p[n - 1])].push_back(i);
	
	int q;
	cin >> q;
	while (q--)
	{
		int f;
		cin >> f;
		int idx = -1;
		int s = 0, e = a - 1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (ans[mid].size())
			{
				if (mid == f)
					idx = 
			}
		}
	}


	return 0;
}
#endif
