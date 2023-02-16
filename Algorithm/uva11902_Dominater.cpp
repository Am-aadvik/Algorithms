#include "CommonHeader.h"

#ifdef UVA11367_FUEL_TANK
READ_INPUT(UVA11367_FUEL_TANK)
#include <iostream>
using namespace std;

int t, n;
bool g[101][101], res[101][101], visited[101], can[101];
void solve(int node, int block)
{
	if (node == block) return;
	visited[node] = 1;
	for (int i = 0; i < n; ++i)
		if (g[node][i] && !visited[i])
			solve(i, block);
	return;
}
void reach(int node)
{
	if (can[node]) return;
	can[node] = 1;
	for (int i = 0; i < n; ++i)
		if (g[node][i])
			reach(i);
}
void print1()
{
	cout << "+";
	for (int i = 1; i < 2 * n; ++i)
		cout << "-";
	cout << "+" << endl;
}
int main()
{
	cin >> t;
	for (int tc = 1; tc <= t; ++tc)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> g[i][j];

		reach(0);
		for (int i = 0; i < n; ++i)
		{
			solve(0, i);
			for (int j = 0; j < n; ++j)
				if (can[j])
					res[i][j] = (!visited[j]), visited[j] = 0;
		}

		cout << "Case " << tc << ":" << endl; print1();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; res[i][j] = 0, g[i][j] = 0, j++)
				cout << (res[i][j] ? "|Y" : "|N");
			cout << "|" << endl; print1(), can[i] = visited[i] = 0;
		}
	}
}
#endif
