#include "CommonHeader.h"

#ifdef USACO_JAN23_P2_FOLLOWDIR
READ_INPUT(USACO_JAN23_P2_FOLLOWDIR)

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

#define FOR(i, init, cnt) for(int i = init; i < cnt; i++)
#define MAXN 1503
#define INF 0x3f3f3f3f3f3f3f3fL
typedef long long ll;

ll grid[MAXN][MAXN];
int dir[MAXN][MAXN];
int cost[MAXN];
int N;

void reset()
{

}

void PrintCostGrid()
{
	FOR(i, 0, N+1)
	{
		FOR(j, 0, N+1)
		{
			cout << grid[i][j] << " ";
		}

		cout << endl;
	}
}


int main()
{

	cin >> N;

	FOR(i, 0, N)
	{
		string s;
		cin >> s;
		FOR(j, 0, N)
		{
			dir[i][j] = (s[j] == 'R') ? 0 : 1;
			grid[i][j] = 0;
		}

		int costLine;
		cin >> costLine;

		grid[i][N] = costLine;
	}

	PrintCostGrid();

	return 0;
}

#endif
