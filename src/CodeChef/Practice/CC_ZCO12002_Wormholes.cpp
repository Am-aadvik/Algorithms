#include "CommonHeader.h"

#ifdef CC_ZCO12002_WORMHOLES
READ_INPUT(CC_ZCO12002_WORMHOLES)
#include <iostream>
#include <algorithm>
#include <math.h>

#define INF 2147483647
using namespace std;

int arr[100001][2], v[100001], w[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//take input
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n; ++i)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 0; i < x; ++i)
		cin >> v[i];
	for (int i = 0; i < y; ++i)
		cin >> w[i];
	//sort arrays
	sort(v, v + x);
	sort(w, w + y);
	//do binary search
	int ans = INF;
	for (int i = 0; i < n; ++i)
	{
		int l = 0, r = x - 1, j = -1;
		while (l <= r)
		{
			int mid = ((l + r) / 2);
			if (v[mid] <= arr[i][0])
				j = mid, l = j + 1;
			else
				r = mid - 1;
		}
		l = 0, r = y - 1;
		int k = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (w[mid] >= arr[i][1])
				k = mid, r = k - 1;
			else
				l = mid + 1;
		}
		if (j != -1 && k != -1)
			ans = fmin(ans, w[k] - v[j] + 1);
	}

	cout << ans;
	return 0;
}
#endif
