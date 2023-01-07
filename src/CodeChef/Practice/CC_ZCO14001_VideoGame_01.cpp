#include "CommonHeader.h"

#ifdef CC_ZCO14001_VIDEOGAME_01
READ_INPUT(CC_ZCO14001_VIDEOGAME_01)

#include <iostream>
using namespace std;

int cntbox[100001];
int main()
{
	int n, h, cpos = 0;
	bool nbox = 1;
	cin >> n >> h;
	for (int i = 0; i < n; ++i)
		cin >> cntbox[i];
	int command = -1;
	while (command != 0)
	{
		cin >> command;
		if (command == 1)
		{
			if (cpos != 0)
				--cpos;
		}
		else if (command == 2)
		{
			if (cpos != n - 1)
				++cpos;
		}
		else if (command == 3)
		{
			if (nbox && cntbox[cpos] > 0)
				nbox = 0, --cntbox[cpos];
		}
		else if (command == 4)
		{
			if (nbox == 0 && cntbox[cpos] < h)
				nbox = 1, ++cntbox[cpos];
			}
		}
	for (int i = 0; i < n - 1; ++i)
		cout << cntbox[i] << " ";

	cout << cntbox[n - 1] << endl;
	return 0;
}


#endif
