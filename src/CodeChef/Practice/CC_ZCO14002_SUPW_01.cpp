#include "CommonHeader.h"

#ifdef CC_ZCO14002_SUPW_01
READ_INPUT(CC_ZCO14002_SUPW_01)

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define INF 2147483647

typedef long long ll;


ll arr[200001], dp[200001][3] = { 0 };

ll solve(ll miss, ll idx, ll n)
{
	//side case
	if (dp[idx][miss] > 0)
		return dp[idx][miss];

	//base case
	if (idx == n)
		return 0;

	//rec case
	ll inc = INF, exc = INF;

	if (miss != 2)
		exc = solve(miss + 1, idx + 1, n);

	inc = arr[idx] + solve(0, idx + 1, n);

	return dp[idx][miss] = fmin(inc, exc);
}

int main()
{
	ll n;
	cin >> n;

	for (ll i = 0; i < n; ++i)
		cin >> arr[i];

	ll ans = solve(0, 0, n);
	cout << ans << endl;

	return 0;
}
#endif