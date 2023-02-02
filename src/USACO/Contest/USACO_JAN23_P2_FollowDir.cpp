#include "CommonHeader.h"
#ifdef USACO_JAN23_P2_FOLLOWDIR
READ_INPUT(USACO_JAN23_P2_FOLLOWDIR)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector> 
#define DEBUG_MODE 
using namespace std;

int grid1[1505][1505], dir2[1505][1505], qi[1505], qj[1505], n, q, reach[1505][1505], dir1[1505][1505];
vector<int> ans1, ans2;

void change2(int i, int j, int effect)
{
	reach[i][j] += effect;
	if (dir2[i][j] && i < n - 1) change2(i + 1, j, effect);
	if (dir2[i][j] == 0 && j < n - 1) change2(i, j + 1, effect);
}
int change1(int i, int j, int fill)
{
	int get1 = (grid1[i][j] - fill); grid1[i][j] = fill;
	if (i > 0 && dir1[i - 1][j] == 1) return change1(i - 1, j, fill) + get1;
	if (j > 0 && dir1[i][j - 1] == 0) return change1(i, j - 1, fill) + get1;
}
int move(int i, int j)
{
	if (grid1[i][j] != -1 || i == n + 1 || j == n + 1) return grid1[i][j];
	return grid1[i][j] = (dir1[i][j] ? move(i + 1, j) : move(i, j + 1));
}
void old_func(int totalCost)
{
	for (int c = 0; c < q; ++c)
	{
		int i2 = qi[c] - 1, j2 = qj[c] - 1, get1; dir1[i2][j2] ^= 1;
		if (dir1[i2][j2]) get1 = change1(i2, j2, grid1[i2 + 1][j2]);
		else get1 = change1(i2, j2, grid1[i2][j2 + 1]);
		totalCost -= get1, ans1.push_back(totalCost);
	}
}
int send(int i, int j)
{
	if (dir2[i][j] > 1) return (dir2[i][j] - 1);
	if (dir2[i][j] == 1) return send(i + 1, j);
	return send(i, j + 1);
}
void new_func(int totalCost)
{
	for (int c = 0; c < q; ++c)
	{
		int i2 = qi[c] - 1, j2 = qj[c] - 1, curr = reach[i2][j2], before = send(i2, j2), after;
		change2(i2, j2, -curr), dir2[i2][j2] ^= 1, change2(i2, j2, curr); after = send(i2, j2);
		totalCost -= ((before - after) * reach[i2][j2]); ans2.push_back(totalCost);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		for (int j = 0; j < n; ++j) dir1[i][j] = dir2[i][j] = (s[j] == 'R') ? 0 : 1, grid1[i][j] = -1;
		cin >> grid1[i][n]; dir2[i][n] = grid1[i][n] + 1;
	}
	for (int j = 0; j < n; ++j)
	{
		cin >> grid1[n][j];
		dir2[n][j] = grid1[n][j] + 1;
	}

	cin >> q;
	for (int j = 0; j < q; ++j) cin >> qi[j] >> qj[j];
	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 1; j >= 0; --j)
			if (grid1[i][j] == -1)
				move(i, j);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			reach[i][j]++;
			if (i > 0 && dir1[i - 1][j]) reach[i][j] += reach[i - 1][j];
			if (j > 0 && dir1[i][j - 1] == 0) reach[i][j] += reach[i][j - 1];
		}
	}

	int totalCost = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			totalCost += grid1[i][j];
	ans1.push_back(totalCost), ans2.push_back(totalCost), new_func(totalCost);
#ifdef DEBUG_MODE
	old_func(totalCost); cout << "Final performance of algorithm : ";
	if (ans1 == ans2) cout << "Accepted!" << endl;
	else cout << "Wrong Answer!" << endl;
#else
	for (int i = 0; i < ans2.size(); ++i)
		cout << ans2[i] << endl;
#endif
}
#endif