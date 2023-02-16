#include "CommonHeader.h"

#ifdef UVA100_THE_3N_PROBLEM
READ_INPUT(UVA100_THE_3N_PROBLEM)

#include <iostream>
#define int long long
const int N = 1000000;
using namespace std;

int32_t main()
{
	int l, r, ans;
	while (scanf("%d%d", &l, &r) != EOF)
	{
		ans = -1e17;
		for (int l = min(l, r); i <= max(l, r); ++i)
		{
			int ans1 = 1, tmp = i;
			while (tmp != 1)
			{
				if (tmp % 2 == 0)
					tmp /= 2;
				else
					tmp *= 3, tmp++;
				ans1++;
			}

			ans = max(ans, ans1);
		}
		cout << l << " " << r << " " << ans << endl;
	}
}
#endif
