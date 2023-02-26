#include "CommonHeader.h"

#ifdef CC_ZCO16002_BAMBOO_ART_01
READ_INPUT(CC_ZCO16002_BAMBOO_ART_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
#define int int64_t
#define INT int32_t
#define MAX_N 100001
#define MAX_VAL 1e18

set<int> arr;
int temp[2501];
INT main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		arr.insert(val);
		temp[i] = val;
	}

	sort(temp, temp + n);

	int ans = -1;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int curr_ans = 2;
			int diff = temp[j] - temp[i];
			int curr = temp[j];
			while (arr.find(curr + diff) != arr.end())
				curr += diff, ++curr_ans;
			ans = fmax(ans, curr_ans);
		}
	}

	cout << ans;
	return 0;
}
#endif
