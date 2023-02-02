#include "CommonHeader.h"

#ifdef USACO_JAN23_P2_FOLLOWDIR_TC_GENERATOR
READ_INPUT(USACO_JAN23_P2_FOLLOWDIR_TC_GENERATOR)

#include <iostream>
using namespace std;

int main()
{
	int n = 1500;
	cout << n << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << (j % 2 ? "R" : "D");
		cout << " " << (i + 1) << endl;
	}
	for (int i = 10; i >= 6; --i)
		cout << i << " ";
	cout << endl;
	for (int i = 1; i <= n; ++i)
		cout << i << " " << i << endl;

	return 0;
}

#endif