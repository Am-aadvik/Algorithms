#include "CommonHeader.h"

#ifdef CF_EXTREMELY_ROUND_01
READ_INPUT(CF_EXTREMELY_ROUND_01)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define int long long
using namespace std;

int32_t main()
{
#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output-Eddie.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		string n;
		int ans = 0;
		cin >> n;

		for (int i = 0; i < n.length(); ++i)
		{
			if (i == 0)
				ans += (n[i] - '0');
			else
				ans += 9;
		}

		cout << ans << endl;
	}
	return 0;
}
#endif
