#include "CommonHeader.h"

#ifdef CC_ZCO17002_RAYS_01
READ_INPUT(CC_ZCO17002_RAYS_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;

#define int int64_t

vector<pair<int, pair<int, bool>>>  block;

bool comp(pair<int, pair<int, bool>> p1, pair<int, pair<int, bool>> p2)
{
	if (p1.first == p2.first)
		return p1.second.first < p2.second.first;

	return p1.first < p2.first;
}

int com(int up)
{
	return ((up * (up + 1)) / 2);
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	int n, m, w, b;
	cin >> n >> m >> w >> b;

	for (int i = 0; i < w; ++i)
	{
		int p1, p2;
		cin >> p1 >> p2;
		block.push_back(make_pair(p1, make_pair(p2, 0)));
	}

	for (int i = 0; i < b; ++i)
	{
		int p1, p2;
		cin >> p1 >> p2;
		block.push_back(make_pair(p1, make_pair(p2, 1)));
	}

	sort(block.begin(), block.end(), comp);

	int j = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int oprev = -1;
		pair<int, bool> prev = { 0,1 };

		for (; j < block.size(); ++j)
		{
			if (block[j].first != i)
				break;

			if (block[j].second.second)//? --//will end at j//--> ? --//will end at j//--> b <---- j
			{
				if (prev.second)//? ----> b --//will end at j//--> b <---- j 
				{
					int up = prev.first == 0 ? block[j].second.first : (block[j].second.first - prev.first);
					ans += com(up);
					ans--;//no ray will come out of current square
				}
				else//? --//will end at j//--> w --//will end at j//--> b <---- j
				{
					int up = oprev == -1 ? block[j].second.first : (block[j].second.first - oprev);
					ans += com(up);
					ans -= (block[j].second.first - prev.first) + 1;//delete path of the white square in between as no ray will come out of it
					ans--;//no ray will come out of current square
				}
			}
			else if (prev.second == 0 && prev.first != 0)//? --//will end at j//--> w -----> w <---- j
			{
				int up = oprev == -1 ? (block[j].second.first) : (block[j].second.first - oprev);
				ans += com(up);
				up = ((block[j].second.first - prev.first) + 1);
				ans -= com(up);//delete paths of rays starting in front of prev square as they will not end at current square
			}

			oprev = prev.first;
			prev = make_pair(block[j].second.first, block[j].second.second);
		}

		//consider rays that reached the end
		if (prev.second)//b.w.b..
		{
			int up = m - prev.first;
			ans += com(up);
		}
		else//w.b.w.w. or ..w. or w.b.w
		{
			int up = 0;
			if (oprev == -1)//..w.
				up = m;

			else //w.b.w.w. or w.b.w
				up = (m - oprev);

			ans += com(up);
			ans -= ((m - prev.first) + 1);//delete path of the white square in between as no ray will come out of it
		}
	}

	cout << ans << endl;
	return 0;
}
#endif
