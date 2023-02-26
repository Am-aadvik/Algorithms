#include "CommonHeader.h"

#ifdef CC_ZCO12003_MATCHED_BRACKETS2
READ_INPUT(CC_ZCO12003_MATCHED_BRACKETS2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <set>
using namespace std;
vector<int> arr;
stack<int> op;
stack<int> curr;

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}

	op.push(-1), curr.push(0);

	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] % 2)
		{
			curr.push(curr.top() + (op.top() != arr[i]));
			op.push(arr[i]);
		}
		else
			curr.pop(), op.pop();

		ans = fmax(ans, curr.top());
	}
	cout << ans << " ";
	int cl = 0, len = 0;
	ans = 0;
	bool inbrack = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 1)
			cl++, inbrack = 1;

		if (inbrack)
			len++;

		if (arr[i] == 2)
		{
			cl--;
			if (cl == 0)
			{
				if (len > ans)
					ans = len;
				len = 0;
				inbrack = 0;
			}
		}
	}
	cout << ans << " ";
	ans = 0, len = 0, cl = 0;
	inbrack = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 3)
			cl++, inbrack = 1;

		if (inbrack)
			len++;

		if (arr[i] == 4)
		{
			cl--;
			if (cl == 0)
			{
				if (len > ans)
					ans = len;
				len = 0;
				inbrack = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
#endif
