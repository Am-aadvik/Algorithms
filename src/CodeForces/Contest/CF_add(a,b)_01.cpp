#include "CommonHeader.h"

#ifdef CF_ADD_A_AND_B_01
READ_INPUT(CF_ADD_A_AND_B_01)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <string>
using namespace std;

#define int long long
#define MAXN 100007
#define MAX 1000000005

bool comp(int a, int b)
{
	return (a > b);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n1 = (s[0] - '0'), n2 = (s[2] - '0');

		cout << (n1 + n2) << endl;
	}
	return 0;
}
#endif
