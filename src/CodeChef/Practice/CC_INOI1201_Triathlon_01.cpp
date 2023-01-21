#include "CommonHeader.h"

#ifdef CC_INOI1201_TRIATHLON_01
READ_INPUT(CC_INOI1201_TRIATHLON_01)

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <float.h>
#include <queue>
#include <map>
#include <stdio.h>
using namespace std;

vector<pair<int, int>> v(200000);

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n;++i)
	{
		int contest, pole_vault, party;
		cin >> contest >> pole_vault >> party;
		v[i].first = contest;
		v[i].second = pole_vault + party;
	}

	sort(v.begin(), v.end(), comp);
	int curr_sum = 0, ans = 0;
	for (int i = 0; i < n; ++i)
		ans = fmax(ans, (curr_sum + v[i].first + v[i].second)), curr_sum += v[i].first;
	cout << ans;
}

#endif
