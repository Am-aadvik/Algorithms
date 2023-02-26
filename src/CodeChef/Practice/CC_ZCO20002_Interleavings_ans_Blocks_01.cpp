#include "CommonHeader.h"

#ifdef CC_ZCO20002_INTERLEAVINGS_ANS_BLOCKS_01
READ_INPUT(CC_ZCO20002_INTERLEAVINGS_ANS_BLOCKS_01)

#include<iostream>
using namespace std;
#define int long long
#define MOD 100000007

int a[101], b[101], dp[101][101][202][2] = { 0 };

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;
        a[0] = -1;
        b[0] = -1;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 1; i <= m; ++i)
            cin >> b[i];

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= d; ++k)
                    dp[i][j][k][0] = dp[i][j][k][1] = 0;

        dp[0][1][1][1] = dp[1][0][1][0] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int k = 1; k <= d; ++k)
            {
                if (a[i] == a[i - 1])
                    dp[i][0][k][0] += dp[i - 1][0][k][0] % MOD;
                else
                    dp[i][0][k][0] += dp[i - 1][0][k - 1][0] % MOD;

                if (b[i] == b[i - 1])
                    dp[0][i][k][1] += dp[0][i - 1][k][1] % MOD;
                else
                    dp[0][i][k][1] += dp[0][i - 1][k - 1][1] % MOD;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                for (int k = 1; k <= d; ++k)
                {
                    if (k > i + j)
                    {
                        dp[i][j][k][0] = dp[i][j][k][1] = 0;
                        continue;
                    }
                    if (a[i] == a[i - 1])
                        dp[i][j][k][0] += dp[i - 1][j][k][0] % MOD;

                    else
                        dp[i][j][k][0] += dp[i - 1][j][k - 1][0] % MOD;

                    if (b[j] == b[j - 1])
                        dp[i][j][k][1] += dp[i][j - 1][k][1] % MOD;

                    else
                        dp[i][j][k][1] += dp[i][j - 1][k - 1][1] % MOD;


                    if (a[i] == b[j])
                    {
                        dp[i][j][k][1] += dp[i][j - 1][k][0] % MOD;
                        dp[i][j][k][0] += dp[i - 1][j][k][1] % MOD;
                    }
                    else
                    {
                        dp[i][j][k][1] += dp[i][j - 1][k - 1][0] % MOD;
                        dp[i][j][k][0] += dp[i - 1][j][k - 1][1] % MOD;
                    }

                    dp[i][j][k][0] %= MOD;
                    dp[i][j][k][1] %= MOD;
                }
            }
        }

        cout << (dp[n][m][d][0] + dp[n][m][d][1]) % MOD << "\n";
    }
    return 0;
}

#endif
