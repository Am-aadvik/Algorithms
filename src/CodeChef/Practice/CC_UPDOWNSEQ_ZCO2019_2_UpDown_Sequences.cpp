#include "CommonHeader.h"

#ifdef CC_UPDOWNSEQ_ZCO2019_2_UPDOWN_SEQUENCES
READ_INPUT(CC_UPDOWNSEQ_ZCO2019_2_UPDOWN_SEQUENCES)
#include<iostream>
using namespace std;

int dp[3][1000005], n, a[1000005];
int f(int state, int i)
{
    if (i > n) return 0;
    if (dp[state][i] != -1) return dp[state][i];
    else
    {
        if (i == n) dp[state][i] = 1;
        else if (state == 0 && a[i] > a[i + 1]) dp[state][i] = 1;
        else if (state == 1 && a[i] < a[i + 1]) dp[state][i] = 1;
        else if (state == 0 && a[i] <= a[i + 1]) dp[state][i] = 1 + f(1, i + 1);
        else if (state == 1 && a[i] >= a[i + 1]) dp[state][i] = 1 + f(0, i + 1);
        return dp[state][i];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < 1000005; ++i) dp[0][i] = dp[1][i] = -1;

        for (int i = n; i >= 0; --i) {f(0, i);f(1, i);}

        int ans = 0;
        for (int i = 0; i <= n; ++i)
        {
            int tmp = dp[0][i];
            if ((tmp + i) == n - 1) ans = max(ans, (tmp + 1));
            else if (tmp % 2 == 0) ans = max(ans, (tmp + 1 + dp[1][i + tmp]));
            else ans = max(ans, (tmp + 1 + dp[0][i + tmp]));
        }
        cout << ans << endl;
    }
}
#endif
