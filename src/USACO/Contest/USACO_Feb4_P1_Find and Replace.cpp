#include "CommonHeader.h"

#ifdef USACO_JAN23_P1_LEADERS
READ_INPUT(USACO_JAN23_P1_LEADERS)

#include <iostream>
#define N 1000005
using namespace std;

int e[N], G_lis[N], H_lis[N], inc_H[N], inc_G[N];
string s;
bool breed_inc[N];

int main()
{
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
        cin >> e[i];

    int Gstart = -1, Gend = -1, Hstart = -1, Hend = -1;
    for (int i = 0; i < n; ++i)
    {
        e[i]--;
        if (s[i] == 'G')
            Gstart = ((Gstart == -1) ? i : Gstart), Gend = i, G_lis[i]++;
        else
            Hstart = ((Hstart == -1) ? i : Hstart), Hend = i, H_lis[i]++;

        if (i > 0)
            H_lis[i] += H_lis[i - 1], G_lis[i] += G_lis[i - 1];
    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'G')
            breed_inc[i] = (G_lis[n - 1] == (G_lis[e[i]] - G_lis[i] + 1)), inc_G[i] = breed_inc[i];
        else
            breed_inc[i] = (H_lis[n - 1] == (H_lis[e[i]] - H_lis[i] + 1)), inc_H[i] = breed_inc[i];

        if (i > 0)
            inc_G[i] += inc_G[i - 1], inc_H[i] += inc_H[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'G')
        {
            if (breed_inc[i])
                ans += (inc_H[n - 1] - inc_H[i]);
            else
                ans += (inc_H[e[i]] - inc_H[i]);
        }
        else
        {
            if (breed_inc[i])
                ans += (inc_G[n - 1] - inc_G[i]);
            else
                ans += (inc_G[e[i]] - inc_G[i]);
        }
    }
    cout << ans << endl;
}

#endif
