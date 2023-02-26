#include "CommonHeader.h"

#ifdef UVA10363_TIC_TAC_TOE
READ_INPUT(UVA10363_TIC_TAC_TOE)
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> vs;

int trios(char op)
{
	int tot = 0, r = 0, c = 0, d = 0;

	for (int i = 0; i < 3; ++i)
		if (vs[i][0] == op && vs[i][1] == op && vs[i][2] == op)
			tot++, r++;

	for (int i = 0; i < 3; ++i)
		if (vs[0][i] == op && vs[1][i] == op && vs[2][i] == op)
			tot++, c++;

	if (vs[0][0] == op && vs[1][1] == op && vs[2][2] == op)
		tot++, d++;

	if (vs[0][2] == op && vs[1][1] == op && vs[2][0] == op)
		tot++, d++;

	if (tot <= 1)
		return tot;

	if (c == 2 || r == 2)
		return 2;

	return 1;
}
int won()
{
	for (int i = 0; i < 3; ++i)
	{
		if (vs[i][0] == 'X' && vs[i][2] == 'X' && vs[i][1] == 'X')
			return 1;
		if (vs[i][0] == 'O' && vs[i][2] == 'O' && vs[i][1] == 'O')
			return 2;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (vs[0][i] == 'X' && vs[1][i] == 'X' && vs[2][i] == 'X')
			return 1;
		if (vs[0][i] == 'O' && vs[1][i] == 'O' && vs[2][i] == 'O')
			return 2;
	}

	if (vs[0][0] == 'X' && vs[1][1] == 'X' && vs[2][2] == 'X')
		return 1;

	if (vs[0][0] == 'O' && vs[1][1] == 'O' && vs[2][2] == 'O')
		return 2;

	if (vs[0][2] == 'X' && vs[1][1] == 'X' && vs[2][0] == 'X')
		return 1;

	if (vs[0][2] == 'O' && vs[1][1] == 'O' && vs[2][0] == 'O')
		return 2;

	return 0;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt)
	{
		int ocnt = 0, xcnt = 0;
		vs.resize(3);

		for (int i = 0; i < 3; ++i)
			cin >> vs[i];

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (vs[i][j] == 'O')
					ocnt++;
				else if (vs[i][j] == 'X')
					xcnt++;
			}
		}

		if (abs(xcnt - ocnt) > 1 || (ocnt - xcnt == 1))
		{
			cout << "no" << endl;
			//if (t != 0)
				//cin >> vs[0];
			vs.clear();
			continue;
		}

		if (won() == 2 && xcnt != ocnt)
		{
			cout << "no" << endl;
			//if (t != 0)
				//cin >> vs[0];
			vs.clear();
			continue;
		}

		if (won() == 1 && xcnt == ocnt)
		{
			cout << "no" << endl;
			//if (t != 0)
				//cin >> vs[0];
			vs.clear();
			continue;
		}

		if (trios('X') + trios('O') > 1)
		{
			cout << "no" << endl;
			//if (t != 0)
				//cin >> vs[0];
			vs.clear();
			continue;
		}

		cout << "yes" << endl;

		//if(t != 0)
		//cin >> vs[0];

		vs.clear();
	}
	return 0;
}
#endif
