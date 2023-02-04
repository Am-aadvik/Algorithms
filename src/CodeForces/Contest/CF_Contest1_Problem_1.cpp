//#include "CommonHeader.h"
//
//#ifdef CF_CONTEST1_PROBLEM_1
//READ_INPUT(CF_CONTEST1_PROBLEM_1)

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define int long long
using namespace std;

#define INF 1e17

int min1(int a, int b) { return a < b ? a : b; }
int max1(int a, int b) { return a > b ? a : b; }

int arr[200001];
bool neg[200001];

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, sum = 0, min2 = INF, negCnt = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			neg[i] = (arr[i] < 0);
			negCnt += neg[i];
			arr[i] = abs(arr[i]);
			sum += arr[i];
		}

		if (negCnt % 2 == 0) { cout << sum << endl; continue; }

		for (int i = 0; i < n; ++i)
			min2 = min1(min2, arr[i]);
		cout << (sum - min2 * 2) << endl;
	}
}
//#endif
