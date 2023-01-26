#include "CommonHeader.h"
#ifdef CC_1202_TABLE_SUM_01
READ_INPUT(CC_1202_TABLE_SUM_01)
#include<iostream>
#include<math.h>
using namespace std;

int a[200005];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        a[i] += (i + 1), a[i] = fmax(a[i], a[i - 1]);
    cout << a[n - 1] << " ";

    int cnt = 0;
    for (int i = n - 1; i > 0; --i)
    {
        a[i] -= n, a[i] = fmax(a[i], a[i + 1]) + 1;
        ++cnt, a[i - 1] += cnt;
        cout << fmax(a[i], a[i - 1]) << " ";
    }
    cout << endl;
}
#endif