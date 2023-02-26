#include "CommonHeader.h"

#ifdef CC_STRIMPOR_SUBSTRING_IMPORTANCE_ZCO2018
READ_INPUT(CC_STRIMPOR_SUBSTRING_IMPORTANCE_ZCO2018)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> s;
vector<vector<int>> xid(3), zid(3);
vector<int> dp;

void solve()
{
    int n, k;
    cin >> n >> k;
    dp.resize(n + 2);
    s.push_back('S');
    for (int i = 0; i < n; ++i)
    {
        char val;
        cin >> val;
        s.push_back(val);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'X')
            xid[((i - 1) % 3)].push_back(i);
        else if (s[i] == 'Z')
            zid[i % 3].push_back(i);
    }

    for (int i = 0; i < 3; i++)
    {
        if (!xid[i].empty())
        {
            for (int id : xid[i])
            {
                auto c = upper_bound(zid[i].begin(), zid[i].end(), id);
                if (c == zid[i].end()) continue;
                int cnt = zid[i].end() - c;
                id = max(1, id - k + 1);
                dp[id] += cnt;
            }
            for (int j = 0; j < zid[i].size(); ++j)
            {
                if (zid[i][j] >= xid[i][0])
                {
                    auto c = upper_bound(xid[i].begin(), xid[i].end(), zid[i][j]);
                    int cnt = c - xid[i].begin();
                    dp[zid[i][j] + 1] -= cnt;
                }
            }
        }
    }
    for (int i = 1; i <= n + 1; ++i)
        dp[i] += dp[i - 1];
    int ans = 1e9;
    for (int i = 1; i <= (n - k + 1); ++i)
        ans = min(ans, dp[i]);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        s.clear();
        xid.clear();
        zid.clear();
        xid.resize(3);
        zid.resize(3);
        dp.clear();
        solve();
    }
    return 0;
}

#endif
