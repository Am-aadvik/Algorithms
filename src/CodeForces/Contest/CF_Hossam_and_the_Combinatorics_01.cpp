#include "CommonHeader.h"

#ifdef CF_HOSSAM_AND_THE_COMBINATORICS_01
READ_INPUT(CF_HOSSAM_AND_THE_COMBINATORICS_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;


//#define DEBUG_MODE
#define MAXN 100007

int arr[MAXN];

int main()
{

#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;

	cin >> t;

	while (t--)
	{
		int N;

		cin >> N;

		for (int i = 0; i < N; ++i)
			cin >> arr[i];

		sort(arr, arr + N);

		int least = arr[0];
		int maxim = arr[N - 1];
		int freq_least = 0;
		int freq_max = 0;

		for (int i = 0; i < N; ++i)
		{
			if (arr[i] == least) ++freq_least;
			if (arr[i] == maxim) ++freq_max;
		}

		if (least == maxim)
			cout << 2 * (freq_least - 1) * freq_least << endl;
		else
			cout << 2 * freq_least * freq_max << endl;
	}


}

#endif
