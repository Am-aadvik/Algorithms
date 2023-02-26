#include "CommonHeader.h"

#ifdef CC_ZCO17001_FOUR_SUM_01
READ_INPUT(CC_ZCO17001_FOUR_SUM_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

#define int unsigned long long
vector<int> arr;
vector<int> sums;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int n, t;
	cin >> n >> t;

	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n < 4) { cout << "0" << endl; return 0; }

	sort(arr.begin(), arr.end());
	sums.resize(t + 1);

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; ((j < n) && (t >= arr[i] + arr[j])); ++j)
			ans += sums[t - arr[i] - arr[j]];

		for (int j = 0; ((j < i) && (arr[i] + arr[j] <= t)); ++j)
			sums[arr[i] + arr[j]]++;
	}

	cout << ans << endl;
}

#endif
