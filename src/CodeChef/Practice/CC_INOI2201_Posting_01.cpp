#include "CommonHeader.h"

#ifdef CC_INOI2201_POSTING_01
READ_INPUT(CC_INOI2201_POSTING_01)

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define int long long
#define pos 1e17

using namespace std;
class office
{
public:
	int c, s, e, d;
	office() { this->c = this->s = this->e = this->d = 0; }
};

office o[10001]; bool task5 = 1, task7 = 1;
int h[30001], n, m, sSum = 0, eSum = 0, hIdx = 0, ans1 = 0;
int min1(int a, int b) { return a < b ? a : b; }

int solve(int idx, int ans)
{
	if (idx == n)
	{
		bool ok = 1;
		for (int i = 0; i < m; ++i)
			ok &= (o[i].c >= o[i].s);
		if (ok) return ans;
		return pos;
	}
	int min_ans = pos;
	for (int i = 0; i < m; ++i)
		if (o[i].c < o[i].e)
		{
			o[i].c++; min_ans = min1(min_ans, solve(idx + 1, (ans + abs(h[idx] - o[i].d)))); o[i].c--;
		}
	return min_ans;
}
bool comp(office a, office b) { return a.d < b.d; }
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> h[i];
	for (int i = 0; i < m; ++i)
	{
		cin >> o[i].d >> o[i].s >> o[i].e; sSum += o[i].s; eSum += o[i].e;
		task5 &= (o[i].s == 0 && o[i].e == n), task7 &= (o[i].s == o[i].e);
	}
	if (task5)
	{
		for (int i = 0; i < n; ++i)
		{
			int curr = pos;
			for (int j = 0; j < m; ++j)
				curr = min1(curr, abs(h[i] - o[j].d));
			ans1 += curr;
		}
		cout << ans1 << endl;
		return 0;
	}
	if (task7 && sSum == n)
	{
		sort(h, h + n); sort(o, o + n, comp);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < o[i].s; ++j)
				ans1 += abs(h[hIdx] - o[i].d), hIdx++;
		cout << ans1 << endl; return 0;
	}
	if (task7 && sSum != n && pow(n,m) > pow(10,8)) { cout << -1 << endl; return 0; }
	int ans2 = solve(0, 0);
	cout << (ans2 > 1e10 ? -1 : ans2);
}
#endif