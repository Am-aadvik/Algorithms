#include "CommonHeader.h"

#ifdef CC_ZCO12004_ROUND_TABLE_01
READ_INPUT(CC_ZCO12004_ROUND_TABLE_01)
#include <iostream>
#define INF 1e17
#define int long long
using namespace std;

int arr[1000001], dp[1000001][3][3][3] = { 0 };
int solve(int miss, int idx, int n, bool inck, bool inl)
{
	if (dp[idx][miss][inck][inl] > 0) return dp[idx][miss][inck][inl];
	if (idx == n) return ((inck || inl) ? (int)0 : min(arr[n - 1], arr[0]));
	int inc = INF, exc = INF;
	if (miss != 1) exc = solve(1, idx + 1, n, inck, inl);
	if (idx == 0) inc = arr[idx] + solve(0, idx + 1, n, 1, inl);
	else if (idx == n - 1) inc = arr[idx] + solve(0, idx + 1, n, inck, 1);
	else inc = arr[idx] + solve(0, idx + 1, n, inck, inl);
	return dp[idx][miss][inck][inl] = min(inc, exc);
}
int32_t main()
{
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	if (n > 1) ans += solve(0, 0, n, 0, 0);
	cout << ans << endl;

}
#endif
