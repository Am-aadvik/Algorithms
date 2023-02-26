#include "CommonHeader.h"

#ifdef UVA10003_CUTTINGSTICKS
READ_INPUT(UVA10003_CUTTINGSTICKS)
#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#define int long long
using namespace std;

int arr[55], dp[55][55], len = 0, cnt = 0;
int solve(int n, int l, int r)
{
	if (r == l + 1)return 0;
	if (dp[l][r] != -1)return dp[l][r];
	cnt++; int ans = 1e9;
	for (int i = l + 1; i < r; ++i) ans = min(ans, (solve(n, l, i) + solve(n, i, r) + (arr[r] - arr[l])));
	return dp[l][r] = ans;
}

int32_t main()
{
	while (1)
	{
		int n; cin >> len;
		if (len == 0)break;
		cin >> n; arr[0] = 0;
		for (int i = 1; i <= n; ++i) cin >> arr[i];
		for (int i = 0; i < 55; ++i)
			for (int j = 0; j < 55; ++j)
				dp[i][j] = -1;
		arr[n + 1] = len;
		cout << "The minimum cutting is " << solve(n, 0, n + 1) << "." << endl;
		cout << cnt << endl;
	}
}
#endif