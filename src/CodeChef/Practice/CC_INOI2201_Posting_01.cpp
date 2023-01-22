#include "CommonHeader.h"

#ifdef CC_INOI2201_POSTING_01
READ_INPUT(CC_INOI2201_POSTING_01)

#include <iostream>
#include <math.h>
#include <vector>
#define int long long
#define pos 1e17
using namespace std;
class office
{
public:
	int c;
	int s;
	int e;
	int d;
	office()
	{
		this->c = 0;
		this->s = 0;
		this->e = 0;
		this->d = 0;
	}
};

office o[10001];
int h[30001];
int min1(int a, int b) { return a < b ? a : b; }

int solve(int idx, int n, int m, int ans)
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
	{
		if (o[i].c < o[i].e)
		{
			o[i].c++;
			min_ans = min1(min_ans, solve(idx + 1, n, m, (ans + abs(h[idx] - o[i].d))));
			o[i].c--;
		}
	}

	return min_ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	for (int i = 0; i < m; ++i)
		cin >> o[i].d >> o[i].s >> o[i].e;

	int ans = solve(0, n, m, 0);
	cout << (ans > 1e10 ? -1 : ans);
	return 0;
}

#endif
