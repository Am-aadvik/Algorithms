#include "CommonHeader.h"


#ifdef CC_NTRIPLETS_01
READ_INPUT(CC_NTRIPLETS_01)

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> nums;
        nums.push_back(1);
        int n;
        cin >> n;
        if(n < 6)
            cout << -1 << endl;
        else
        {
        for(int i = 2; i <= sqrt(n);++i)
        {
            if(n % i == 0 && i != (n / i))
            {
                nums.push_back(i);
                nums.push_back(n / i);
                break;
            }
        }
        
        if(nums.size() == 3)
            cout << "1 " << nums[1] << " " << nums[2] << endl;
        else
        cout << "-1" << endl;
        }
    }
    return 0;
}

#endif
