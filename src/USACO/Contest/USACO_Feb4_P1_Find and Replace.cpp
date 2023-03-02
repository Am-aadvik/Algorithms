#include "CommonHeader.h"

#ifdef USACO_FEB4_P1_FIND_AND_REPLACE
READ_INPUT(USACO_FEB4_P1_FIND_AND_REPLACE)


#include <iostream>
#define N 1000005
using namespace std;

char assign[200]; bool p2[27];
int visited[200]; bool p1[27];


pair<int, bool> solve(int node, int cnt)
{
	if (assign[node] || visited[node] == 2)
		return make_pair(cnt, 0);
	if (visited[node] == 1)
		return make_pair(cnt + 2, 1);
	visited[node] = 1;

	pair<int, bool> curr = solve(assign[node], cnt + 1);
	visited[node] = 2;
	return curr;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 200; ++i)
			assign[i] = '1', visited[i] = 0;

		for (int i = 0; i < 26; ++i)
			p1[i] = p2[i] = 0;

		string s1, s2;
		bool ok = 1, ext = 0;
		cin >> s1 >> s2;

		int n = s1.length();

		for (int i = 0; i < n; ++i)
			if (s1[i] != s1[i])
			{
				if (assign[s1[i]] != '1' && assign[s1[i]] != s2[i])
					ok = 0;

				if (s1[i] < 95)
					p1[s1[i] - 65] = 1;
				else
					p2[s1[i] - 97] = 1;

				assign[s1[i]] = s2[i];
			}

		if (!ok)
		{
			cout << "-1" << endl;
			continue;
		}
		for (int i = 0; i < 26; ++i)
			if (!p1[i] || !p2[i])
				ext = 0;

		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (!visited[s1[i]])
			{
				pair<int, bool> res = solve(s1[i], 0);
				if (res.second && !ext)
					ok = 0;
				ans += res.first;
			}

		if (!ok)
			cout << "-1" << endl;
		else
			cout << ans << endl;
	}
}


#endif
