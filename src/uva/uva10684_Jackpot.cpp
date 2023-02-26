#include "CommonHeader.h"

#ifdef UVA10684_JACKPOT
READ_INPUT(UVA10684_JACKPOT)
#include <iostream>
using namespace std;

int arr[10005];
int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		bool pos = 0;
		for (int i = 0; i < n; ++i)
			if (arr[i] > 0)
				pos = 1;
		if (!pos)
			cout << "Losing streak." << endl;
		else
		{
			int ans = -1, curr = 0;
			for (int i = 0; i < n; ++i)
			{
				curr += arr[i];
				if (curr < 0)
					curr = 0;
				ans = max(ans, curr);
			}

			cout << "The maximum winning streak is " << ans << "." << endl;
		}
	}
}

#endif
