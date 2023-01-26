#include "CommonHeader.h"

#ifdef CC_INOI1401_HIGHWAY_BYPASS_01
READ_INPUT(CC_INOI1401_HIGHWAY_BYPASS_01)
#include <iostream>
using namespace std;

long long dp[305][305][3][305] = { 0 }, grid[305][305] = { 0 };
int32_t main()
{
	int n, d, m; cin >> n >> m >> d;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> grid[i][j];

	dp[n][m][1][0] = dp[n][m][2][0] = 1;
	for (int i = n; i > 0; --i)
	{
		for (int j = m; j > 0; --j)
		{
			if ((i == n && j == m) || !grid[i][j])  continue;

			for (int k = 1; k <= d; ++k)
				dp[i][j][1][k] = dp[i + 1][j][1][k - 1] % 20011, dp[i][j][1][1] += dp[i + 1][j][2][k] % 20011;
			for (int k = 1; k <= d; ++k)
				dp[i][j][2][k] = dp[i][j + 1][2][k - 1] % 20011, dp[i][j][2][1] += dp[i][j + 1][1][k] % 20011;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= d; ++i)
		ans += ((dp[1][1][1][i] + dp[1][1][2][i]) % 20011);
	cout << (ans % 20011) << endl;
}
#endif