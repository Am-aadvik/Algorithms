#include "CommonHeader.h"
#ifdef CC_ZCO23001_PARCHMENT_01
READ_INPUT(CC_ZCO23001_PARCHMENT_01)

#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 
using namespace std;

int p[2000001];
int up_bnd[1000001];
int ans[200001];
int freq[200001];

int compute(int k, int mn, int mx)
{
	int cnt = 0;
	while (mn <= mx)
	{
		mn += k;
		cnt++;
		if (mn >= mx)
			break;
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

	int unique = 0;
	for (int i = 0; i < n; ++i)
		if (freq[p[i]] == 0)
			freq[p[i]] = 1, unique++;

	sort(p, p + n);

	int prev = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = prev; j < p[i]; ++j)
			up_bnd[j] = p[i];
		prev = p[i];
	}

	for (int k = 0; k < a; ++k)
		ans[k] = compute(k, p[0], p[n - 1]);

	int q;
	cin >> q;
	while (q--)
	{
		int f;
		cin >> f;
		if (f >= unique)
			cout << 0 << endl;
		else
		{
			int idx = -1;
			int s = 0, e = p[n - 1];
			while (s <= e)
			{
				int mid = (s + e) / 2;
				if (ans[mid] <= f)
					idx = mid, e = mid - 1;
				else
					s = mid + 1;
			}

			cout << idx << endl;
		}
	}
	return 0;
}

#endif
