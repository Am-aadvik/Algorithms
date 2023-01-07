#include "CommonHeader.h"

#ifdef CC_ZCO12001_MATCHBRACKETS_01
READ_INPUT(CC_ZCO12001_MATCHBRACKETS_01)
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll arr[100001];
vector<ll> unmatch_bracks;

int main()
{
	ll n;
	cin >> n;
	//take input
	for (ll i = 0; i < n; ++i)
		cin >> arr[i];

	//find nesting depth and the first position that acheives it
	ll mcnt = 0, epos = 0, mepos = 0;
	for (ll i = 0; i < n; ++i)
	{
		if (arr[i] == 1)
		{
			unmatch_bracks.push_back(i);
			epos = i;
		}
		else
		{
			if (unmatch_bracks.size() > mcnt)
				mcnt = unmatch_bracks.size(), mepos = epos;

			unmatch_bracks.pop_back();

			if (unmatch_bracks.empty())
				epos = 0;
			else
				epos = unmatch_bracks[unmatch_bracks.size() - 1];
		}
	}

	cout << mcnt << " " << (mepos + 1) << " ";

	// find length of the maximum sequence between matching brackets and the first position where such a maximum length sequence occurs.
	ll rdep = 0, mdep = 0, s = 0, pdep = 0;

	bool isend = 1;
	for (ll i = 0; i < n; ++i)
	{
		if (arr[i] == 1)
		{
			++rdep;
			if (isend == 1)
				isend = 0, s = i;
		}
		else
			--rdep;
		if (rdep == 0)
		{
			isend = 1;
			if (mdep < ((i - s) + 1))
				pdep = s, mdep = ((i - s) + 1);
		}
	}

	cout << mdep << " " << (pdep + 1) << endl;
	return 0;
}

#endif
