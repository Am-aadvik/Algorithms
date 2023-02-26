#include "CommonHeader.h"

#ifdef CC_ZCO13001_TOURNAMENT_01
READ_INPUT(CC_ZCO13001_TOURNAMENT_01)

#include <iostream>
#include<algorithm>
#define int long long
using namespace std;

int arr[200001];
int32_t main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n); int ans = 0;
    for (int i = 0; i < n; i++) ans += (arr[i] * i);
    for (int i = 0; i < n; i++) ans -= (arr[i] * (n - (i + 1)));
    cout << ans;
}
#endif
