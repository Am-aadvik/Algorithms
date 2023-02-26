#include "CommonHeader.h"

#ifdef CC_ZCO13003_CHEWING_01
READ_INPUT(CC_ZCO13003_CHEWING_01)
#include <iostream>
#include <algorithm>

using namespace std;


typedef long long ll;


ll arr[200001];


int main()
{
	ll n, k;
	cin >> n >> k;


	for (ll i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	ll j = 0;

	for (; j < n; ++j)
		if (arr[j] >= k)
			break;

	--j;

	ll i = 0, ans = 0;

	while (i < j)
	{
		if (arr[i] + arr[j] < k)
			ans += (j - i), ++i;
		else
			--j;
	}

	cout << ans << endl;
	return 0;
}


#endif
