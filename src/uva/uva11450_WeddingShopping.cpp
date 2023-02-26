#include "CommonHeader.h"

#ifdef UVA11450_WEDDINGSHOPPING
READ_INPUT(UVA11450_WEDDINGSHOPPING)

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

#include <iostream>
using namespace std;

int arr[25][25], dp[215][25], N;
int solve(int n, int m, int i)
{
    if (n < 0) return -2;
    if (i == m) return N - n;
    if (dp[n][i] != -1)  return dp[n][i];
    int ans = -1;
    for (int j = 1; j <= arr[i][0]; ++j) ans = max(ans, solve(n - arr[i][j], m, i + 1));
    return dp[n][i] = ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m; N = n;
        for (int i = 0; i < m; ++i)
        {
            cin >> arr[i][0];
            for (int j = 1; j <= arr[i][0]; ++j)
                cin >> arr[i][j];
        }

        for (int i = 0; i < 215; ++i)
            for (int j = 0; j < 25; ++j)
                dp[i][j] = -1;

        int ans = solve(n, m, 0);
        if (ans == -1) cout << "no solution" << endl;
        else cout << ans << endl;
    }
}

#endif
