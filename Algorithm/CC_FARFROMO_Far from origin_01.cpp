#ifndef ONLINE_JUDGE
#include "CommonHeader.h"
#ifdef CC_FARFOR_FARFROMORIGIN_01
READ_INPUT(CC_FARFOR_FARFROMORIGIN_01)
#endif
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 
using namespace std;

int min1(int a, int b) { return a < b ? a : b; }
int max1(int a, int b) { return a > b ? a : b; }

int comb[500003];

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n*2; ++i)
			cin >> comb[i];
		
		sort(comb, (comb + (2 * n)));

		int ans = 1e18;
		for (int i = 0; i < n; ++i)
			ans = min1(ans, (comb[i + n] - comb[i]));

		cout << ans << endl;
	}
	return 0;
}
//#endif