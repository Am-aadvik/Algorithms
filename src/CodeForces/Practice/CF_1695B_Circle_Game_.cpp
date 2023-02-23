#include "CommonHeader.h"
#ifndef CF_CONTEST1_PROBLEM_1
READ_INPUT(CF_CONTEST1_PROBLEM_1)

#include <iostream>
#include<vector>
#include<algorithm>

vector<pair<int, int>> arr;
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			arr.push_back({ val,i });
		}

		if (n % 2 == 0)
		{
			sort(arr.begin(), arr.end());
			if (arr[0].second % 2)
				cout << "Mike" << endl;
			else
				cout << "Joe" << endl;
		}
		else
		{

		}


	}
}
#endif