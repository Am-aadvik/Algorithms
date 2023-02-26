#include "CommonHeader.h"

#ifdef CC_ZCO14004_IPL
READ_INPUT(CC_ZCO14004_IPL)

#include <iostream>
#define int long long
using namespace std;

int arr[200001], dp[200001][3] = { 0 };
int solve(int done, int idx, int n)
{
	if (dp[idx][done] > 0) return dp[idx][done];
	if (idx == n) return 0;
	int inc = -1, exc = -1;
	if (done != 2) inc = arr[idx] + solve(done + 1, idx + 1, n);
	exc = solve(0, idx + 1, n); return dp[idx][done] = max(inc, exc);
}
int32_t main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cout << solve(0, 0, n) << endl;
}
#endif