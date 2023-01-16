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
int ans[200001][2];

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

	for (int k = 0; k < a; ++k)
		ans[k][0] = compute(k, p[0], p[n - 1]);
	
	int q;
	cin >> q;
	while (q--)
	{
		int f;
		cin >> f;
		if (f >= n)
			cout << 0 << endl;
		else
		{
			int idx = -1;
			int s = 0, e = a - 1;
			while (s <= e)
			{
				int mid = (s + e) / 2;
				if (ans[mid][0] == f)
					idx = mid, e = mid - 1;
				else if (ans[mid][0] < f)
					e = mid - 1;
				else
					s = mid + 1;
			}

			cout << idx << endl;
		}
	}


	return 0;
}
#endif
