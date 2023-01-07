#include "CommonHeader.h"

#ifdef CC_ZCO14003_SMARTPHONE_01
READ_INPUT(CC_ZCO14003_SMARTPHONE_01)


#include <iostream>
#include <algorithm>

long long times, budgets[500001], max1 = 0, current;
using namespace std;
void swap(int i, int j)
{
    int temp = budgets[i];
    budgets[i] = budgets[j];
    budgets[j] = temp;
}
int main()
{
    scanf("%lld", &times);
    for (int i = 0; i < times; ++i)
    {
        scanf("%lld", &budgets[i]);
    }

    sort(budgets, budgets + times);

    for (int i = 0; i < times; ++i)
        if (budgets[i] * (times - i) > max1)
            max1 = budgets[i] * (times - i);

    printf("%lld", max1);
    return 0;
}

#endif