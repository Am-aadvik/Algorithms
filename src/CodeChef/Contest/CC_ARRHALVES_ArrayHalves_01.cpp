#include "CommonHeader.h"

#ifdef CC_ARRHALVES_ARRAYHALVES_01
READ_INPUT(CC_ARRHALVES_ARRAYHALVES_01)
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <float.h>
#include <queue>
#include <map>
#include <stdio.h>
#define int long long
using namespace std;

#define FOR(i, init, cnt) for(int i = init; i < cnt; i++)
#define MAXN 1003
#define INF 0x3f3f3f3f3f3f3f3fL

int arr[200002], go[200002];

void swap1(int i, int j) { int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp; }
void swap2(int i, int j) { int tmp = go[i]; go[i] = go[j]; go[j] = tmp; }

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		m = 2 * n;
		for (int i = 0; i < m; ++i)
			cin >> arr[i];

		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; ++i)
			if (arr[i] > n)
				go[i] = 1, cnt1++;
		for (int i = n; i < m; ++i)
			if (arr[i] <= n)
				go[i] = 1, cnt2++;

		int ans = 0, lst0 = 1e9;
		for (int i = n - 1; i >= 0; --i)
		{
			if (go[i] && lst0 <= m)
				ans += (lst0 - i), lst0--;
			else if (lst0 > m && go[i] == 0)
				lst0 = i;
		}

		lst0 = 1e9;
		for (int i = n; i < m; ++i)
		{
			if (go[i] && lst0 <= m)
				ans += (i - lst0), lst0++;
			else if (lst0 > m && go[i] == 0)
				lst0 = i;
		}

		cout << (ans + (cnt1 * cnt2)) << endl;
		for (int i = 0; i < m; ++i)
			go[i] = 0;
	}
	return 0;
}
#endif
