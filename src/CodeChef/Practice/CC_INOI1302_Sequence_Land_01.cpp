#include "CommonHeader.h"

#ifdef CC_INOI_SEQUENCE_LAND_01
READ_INPUT(CC_INOI_SEQUENCE_LAND_01)

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

vector<vector<int>> arr;
bool graph[301][301];
bool visited[301];
queue<int> bfs;
vector<map<int, int>> freq;

bool find1(vector<int> in, int key)
{
	int s = 0, e = 0;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (in[mid] == key)
			return 1;
		else if (in[mid] > key)
			e = mid - 1;
		else
			s = mid + 1;
	}
	return 0;
}

int main()
{
	int n, k;
	cin >> n >> k;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int size;
		cin >> size;

		for (int j = 0; j < size; ++j)
		{int val; cin >> val; arr[i].push_back(val);}

		sort(arr[i].begin(), arr[i].end());
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int common = 0;
			for (int k = 0; k < arr[i].size(); ++k)
				if (find1(arr[j], arr[i][k]))
					common++;

			if (common >= k)
				graph[i][j] = graph[j][i] = 1;
		}
	}

	int ans = 0;
	bfs.push(0);
	while (!bfs.empty())
	{
		int top = bfs.front();
		visited[top] = 1;
		bfs.pop();
		for (int i = 0; i < n; ++i)
			if (graph[top][i] && visited[i] == 0)
				ans++, bfs.push(i);
	}

	cout << ans;
	return 0;
}
#endif
