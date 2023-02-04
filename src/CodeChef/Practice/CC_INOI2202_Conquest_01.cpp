#include "CommonHeader.h"
#define _CRT_SECURE_NO_WARNINGS

#ifdef CC_INOI2202_CONQUEST_01
READ_INPUT(CC_INOI2202_CONQUEST_01)

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
#define int long long

class segement_tree
{
public:
	int ans[2][2];
	segement_tree(int v) { ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = 0, ans[1][1] = v; }
	segement_tree() { ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = 0; }
};
segement_tree comb(segement_tree L, segement_tree R)
{
	segement_tree r;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
					if (a != 1 || b != 1)
						r.ans[i][j] = fmax(r.ans[i][j], L.ans[i][a] + R.ans[b][j]);
	return r;
}

int n, q, arr[500001], queries[500001][2], dp[500001],v[500005], skip[500005],take[500005]
,dp1[500005]; vector<int> adj[500001]; bool task8 = 1; segement_tree seg[2000004];

int find_max(segement_tree curr) { return fmax(fmax(curr.ans[0][0], curr.ans[0][1]), fmax(curr.ans[1][0], curr.ans[1][1])); }
void build(int ind, int l, int r)
{
	if (l == r) { seg[ind] = segement_tree(arr[l]); return; }
	int m = (l + r) / 2;
	build(ind * 2, l, m);
	build(ind * 2 + 1, m + 1, r);
	seg[ind] = comb(seg[ind * 2], seg[ind * 2 + 1]);
}
segement_tree query(int ind, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr) return seg[ind];
	if (ql > r || qr < l) return segement_tree();
	int m = (l + r) / 2;
	return comb(query(ind * 2, l, m, ql, qr), query(ind * 2 + 1, m + 1, r, ql, qr));
}
void dfs1(int node, int parent, int oprev, int prev)
{
	dp[node] = fmax(oprev + arr[node], prev);
	for (int i = 0; i < adj[node].size(); ++i)
		if (adj[node][i] != parent)
		dfs1(adj[node][i], node, prev, dp[node]);
}
void dfs(int node, int parent)
{
	skip[node] = max(skip[parent], take[parent]),take[node] = skip[parent] + v[node];
	for (int u = 0; u < adj[node].size();++u) 
		if (adj[node][u] != parent) 
			dfs(u, node);
}
void dfs2(int node, int parent, int l1, int l2) 
{
	dp1[node] = max(l1 + v[node], l2);
	for (int u = 0; u < adj[node].size(); ++u)
		if (adj[node][u] != parent)
			dfs2(u, node,l2,dp1[node]);
}
int32_t main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < q; ++i) { cin >> queries[i][0] >> queries[i][1]; task8 &= (queries[i][0] == 1); };
	if (task8)
	{
		for (int u = 0; u < adj[1].size(); ++u) dfs(u, 1);
		dfs2(1, 1, 0, 0);
		for (int i = 0; i < q; ++i)
			if (queries[i][0] == 1)
				cout << dp1[queries[i][1]] << endl;
			else if (queries[i][1] == 1)
				cout << dp1[queries[i][0]] << endl;
			else
				cout << fmax(fmax(take[queries[i][0]] + take[queries[i][1]],
					fmax(skip[queries[i][0]] + v[1] + skip[queries[i][1]], take[queries[i][0]] + skip[queries[i][1]])),
					skip[queries[i][0]] + take[queries[i][1]]) << endl;
	}

	build(1, 1, n);
	for (int i = 0; i < q; ++i)
	{
		cin >> queries[i][0] >> queries[i][1];
		int l2 = fmin(queries[i][0], queries[i][1]), r2 = fmax(queries[i][0], queries[i][1]);
		segement_tree curr = query(1, 1, n, l2, r2);
		cout << find_max(curr) << endl;
	}
}
#endif