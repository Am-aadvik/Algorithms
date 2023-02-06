#include "CommonHeader.h"
#include <vector>
#ifdef USACO_FEB4_P1_FIND_AND_REPLACE
READ_INPUT(USACO_FEB4_P1_FIND_AND_REPLACE)

vector<vector<int>> g(201);
int memo[201], freq[201];

pair<int,bool> solve(int node, int cnt)
{
	if (memo[node] == 2) { return { cnt,0 }; }
	if (memo[node] == 1) { memo[node] = 2; return { cnt + 1,1 }; }
	memo[node] = 1;
	if (g[node].size()) { memo[node] = 2; return solve(g[node][0], cnt);}
	return { cnt,0 };
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2; int n, unique = 0;
		cin >> n >> s1 >> s2;
		for (int i = 0; i < n; ++i) 
			g[s1[i]].push_back(s2[i]), g[s2[i]].push_back(s1[i]);

		for (int i = 0; i < n; ++i) freq[s1[i]] = 0;
		for (int i = 0; i < n; ++i) {if (!freq[s1[i]]) unique++; freq[s1[i]] = 1;}

		int ans = 0; bool extra = (unique == 52);
		for (int i = 0; i < n; ++i)
		{
			if (!memo[s1[i]])
			{
				pair<int,bool> curr = solve(s1[i], 0);
				if (curr.second && !extra) { ans = -1; break; }
				ans += curr.first;
			}
		}
		cout << ans << endl;
	}
}
#endif