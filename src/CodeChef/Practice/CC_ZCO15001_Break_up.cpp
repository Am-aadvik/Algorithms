#include "CommonHeader.h"

#ifdef CC_ZCO15001_BREAK_UP
READ_INPUT(CC_ZCO15001_BREAK_UP)
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;
bool ispal(vector<ll> arr, ll i, ll j)
{
	while (i <= j)
	{
		if (arr[i] != arr[j])
			return 0;
		++i, --j;
	}
	return 1;
}
int main()
{
	ll n;
	cin >> n;
	vector<ll> dp(n);
	vector<ll> arr(n);
	//take input
	for (ll i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i] = i + 1;
	}
	// find c for each idx
	for (ll i = 1; i < n; ++i)
	{
		for (ll j = 0; j <= i; ++j)// iterate till i
		{
			if (ispal(arr, j, i))//if palindrome between i and j
			{
				if (j == 0)//if palindrome betwen start and i
				{
					dp[i] = 1;//1 palindrome till i
					break;//smallest value possible, no need to go further
				}
				else
				{
					dp[i] = fmin(dp[i], dp[j - 1] + 1);
					//we already computed c for j - 1 
					//c from j to i is 1 so we update
					//c of i to the min of c of i and (c of j - 1) + 1
				}
			}
		}
	}
	//finnaly we print c of last idx
	cout << dp[n - 1] << endl;


	return 0;
}


#endif
