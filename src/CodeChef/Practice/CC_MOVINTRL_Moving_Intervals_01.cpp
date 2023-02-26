#include "CommonHeader.h"

#ifdef CC_MOVINTRL_MOVING_INTERVALS_01
READ_INPUT(CC_MOVINTRL_MOVING_INTERVALS_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

vector<pair<int, pair<int, int>>> arr;
bool comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
	if (p1.first != p2.first) return p1.first < p2.first;
	if ((p1.second.first % 2) != (p2.second.first % 2)) return (p1.second.first % 2) < (p2.second.first % 2);
	return (p1.second.first < p2.second.first);
}

int valid(int max_do, int n, int c)
{
	int emp_space = (arr[0].first - 1); bool can_cont = 1; stack<int> s; s.push(0);int max_do2 = 0;
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i].second.first % 2)
		{
			s.pop();
			if (arr[i].second.first == arr[max_do].second.first + 1) max_do2 = i;
		}
		else
		{
			if (arr[i - 1].second.first % 2 && !s.size()) emp_space = max(emp_space, (arr[i].first - arr[i - 1].first - 1));
			s.push(i);
		}
	}

	if (emp_space > arr[max_do].second.second) return 1;
	int f = (max_do ? (arr[max_do].first - arr[max_do - 1].first - 1) : arr[max_do].first - 1), i = max_do + 1;
	int b = (max_do2 != arr.size() - 1 ? (arr[max_do2 + 1].first - arr[max_do2].first - 1) : (c - arr[max_do2].first));
	while (i < max_do2)
	{
		if (!can_cont) return 0;
		if (arr[i].second.first % 2)
		{
			can_cont = 0;
			if (f < ((arr[i].first + 1) - arr[max_do].first)) return 0;
		}
		else if (b < (arr[max_do2].first + 1) - arr[i].first) return 0;
		++i;
	}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--)
	{
		bool is_ok = 1, valid1 = 1;
		int k,c, n; cin >> c >> n >> k; arr.clear();
		for (int i = 0; i < n; ++i)
		{
			pair<int, int> curr; cin >> curr.first >> curr.second;
			arr.push_back(make_pair(curr.first, make_pair(i * 2, (curr.second - curr.first) + 1)));
			arr.push_back(make_pair(curr.second, make_pair(i * 2 + 1, -1)));
		}

		sort(arr.begin(), arr.end(), comp);
		if (n == 1) {cout << "Good" << endl;continue;}
		if (k == 0)
		{
			sort(arr.begin(), arr.end());
			for (int i = 0; i < arr.size(); i += 2)
				if (arr[i + 1].second.first != (arr[i].second.first + 1)) 
					{valid1 = 0;break;}
			if (valid1) cout << "Good" << endl;
			else cout << "Bad" << endl;
		}
		else
		{
			stack<int> s; stack<pair<int, int>> p;
			for (int i = 0; i < arr.size(); ++i)
			{
				if (arr[i].second.first % 2)
				{
					queue<int> q;
					while (!s.empty())
					{
						if (arr[s.top()].second.first != arr[i].second.first - 1) q.push(s.top());
						s.pop();
					}
					while (!q.empty()) s.push(q.front()), q.pop();
				}
				else
				{
					if (s.size() == 2) {is_ok = 0;break;}
					if (s.size()) p.push(make_pair(s.top(), i));
					s.push(i);
				}
			}
			if (is_ok)
			{
				if (p.size() == 1) is_ok = (valid(p.top().first, n, c) + valid(p.top().second, n, c));
				else if (p.size())
				{
					int t1 = p.top().first, t2 = p.top().second; s.pop();
					int s1 = p.top().first, s2 = p.top().second; s.pop();

					if (s1 != t1 && s1 != t2 && s2 != t1 && s2 != t2) is_ok = 0;
					else
					{
						int max_do = ((t1 == s1) ? t1 : (t1 == s2) ? t1 : t2);
						while (!p.empty())
						{
							t1 = s1, t2 = s2, s1 = p.top().first, s2 = p.top().second; p.pop();
							if (max_do != s1 && max_do != s2) {is_ok = 0;break;}
						}
						if (is_ok) is_ok = valid(max_do, n, c);
					}
				}
			}
			if (is_ok) cout << "Good" << endl;
			else cout << "Bad" << endl;
		}
	}
}
#endif