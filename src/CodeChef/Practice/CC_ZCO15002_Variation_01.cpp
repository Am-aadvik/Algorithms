#include "CommonHeader.h"

#ifdef CC_ZCO15002_VARIATION_01
READ_INPUT(CC_ZCO15002_VARIATION_01)
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int i = 0, j = 1, ans = 0;

	while (j < n)
	{
		if (arr[j] - arr[i] < k)
			++j;
		else
			ans += (n - j), ++i;
	}

	cout << ans << endl;
	return 0;
}
#endif
