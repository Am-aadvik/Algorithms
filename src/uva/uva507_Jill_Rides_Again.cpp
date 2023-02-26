#include "CommonHeader.h"

#ifdef UVA507_JILL_RIDES_AGAIN
READ_INPUT(UVA507_JILL_RIDES_AGAIN)
#include <iostream>
using namespace std;

int arr[20005];
int main()
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; ++c)
    {
        int n;
        cin >> n;
        n--;

        for (int i = 1; i <= n; ++i)
            cin >> arr[i];

        int ans = (-1e9), curr = 0, x, y, cx = 1;
        for (int i = 1; i <= n; ++i)
        {
            curr += arr[i];
            if (curr < 0)
                curr = 0, cx = i + 1;
            if (curr > ans || (curr == ans && ((y - x) < (i - cx))))
                ans = curr, x = cx, y = i;
        }

        if (ans <= 0)
            cout << "Route " << c << " has no nice parts" << endl;
        else
            cout << "The nicest part of route " << c << " is between stops " << x << " and " << (y + 1) << endl;
    }

    return 0;
}
#endif
