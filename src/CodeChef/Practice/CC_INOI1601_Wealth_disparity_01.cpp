#include "CommonHeader.h"

#ifdef CC_INOI1601_WEALTH_DISPARITY_01
READ_INPUT(CC_INOI1601_WEALTH_DISPARITY_01)
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

vector<vector<int>> t;
vector<int> arr(100001);
int ans = 0;

int dfs(int root)
{
	int min1 = arr[root]; 
	for (int i = 0; i < t[root].size(); ++i) min1 = fmin(min1, dfs(t[root][i]));
	ans = fmax(ans, arr[root] - min1); return min1;
}
int main()
{
	int n, root = -1;  cin >> n;  t.resize(n);

	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) { int val; cin >> val; if (val == -1) root = i; else t[val - 1].push_back(i); }

	dfs(root);
	cout << ans << endl;
	return 0;
}
#endif