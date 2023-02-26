#include "CommonHeader.h"

#ifdef CC_ZCO16001_BOOKSHELVES
READ_INPUT(CC_ZCO16001_BOOKSHELVES)
#include <iostream>
#include <math.h>
#include <set>
using namespace std;
#define INT int32_t
#define int INT
#define MAX_N 100001
#define MAX_VAL 1e9

multiset<int> s1, s2;
int a1[100001], a2[100001];
INT main()
{
	//take input
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> a1[i];
	for (int i = 0; i < n; ++i)
		cin >> a2[i];

	for (int i = 0; i < n; ++i)
		s1.insert(a1[i]);

	for (int i = 0; i < n; ++i)
		s2.insert(a2[i]);
	//initialize iterators, ans and temp

	int ans1 = (*(--s1.end()) + *(--s2.end()));
	int ans2 = (*(--s1.end()) + *(--s2.end()));
	int temp = k;
	//op 1: swap first element from s1 and last element from s2
	while (k--)
	{
		//find first element in s1 and last element in s2
		int s = *s1.begin(), e = *(--s2.end());
		//swap them
		s1.erase(s1.begin());
		s2.erase((--s2.end()));
		s1.insert(e);
		s2.insert(s);
		//find min of prev skew and current skew
		ans1 = fmin(ans1, (*(--s1.end()) + *(--s2.end())));
	}
	//re - initializing

	s1.clear();
	s2.clear();
	for (int i = 0; i < n; ++i)
		s1.insert(a1[i]);
	for (int i = 0; i < n; ++i)
		s2.insert(a2[i]);

	//op 2: swap first element from s4 and last element from s3
	while (temp--)
	{
		//find first element in s4 and last element in s3
		int s = *s2.begin(), e = *(--s1.end());
		//swap them
		s1.erase((--s1.end()));
		s2.erase(s2.begin());
		s1.insert(s);
		s2.insert(e);
		//find min of prev skew and current skew
		ans2 = fmin(ans2, (*(--s1.end()) + *(--s2.end())));
	}
	//print ans

	cout << fmin(ans1, ans2) << endl;
	return 0;
}
#endif
