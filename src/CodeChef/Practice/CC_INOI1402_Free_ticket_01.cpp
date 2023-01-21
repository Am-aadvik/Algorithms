#include "CommonHeader.h"

#ifdef CC_INOI_FREE_TICKET_01
READ_INPUT(CC_INOI_FREE_TICKET_01)
#include <iostream>
using namespace std;

const long long max2 = 1e12;

long long graph[241][241];
long long max1(long long a, long long b) { return a > b ? a : b; }
long long min1(long long a, long long b) { return a < b ? a : b; }

int main()
{
	for (long long i = 0; i < 241; ++i)
		for (long long j = 0; j < 241; ++j)
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = max2;

	long long c, f;
	cin >> c >> f;
	for (int i = 0; i < f; ++i)
	{
		long long n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		n1--; n2--;
		graph[n1][n2] = cost;
		graph[n2][n1] = cost;
	}

	//a short implementation of floyd - warshall's algorithm
	for (int k = 0; k < c; ++k)//we want to reach j from i via k
		for (int i = 0; i < c; ++i)//ith vertice is our source
			for (int j = 0; j < c; ++j)//jth vertice is our destination
				graph[i][j] = min1(graph[i][j], (graph[i][k] + graph[k][j]));//take min of dist(i,j) & dist(i,k) + dist(j,k)
//the above line is to check wether the shortest route from i to j via k is shorter than the minimum route so far	
//as we have to find a max2 shortest path from all nodes I used floyd-warshall's algorithm for all-pairs shortest paths
//finnaly as we have the shortest paths between all pairs we take the maximum shortest path
	long long ans = -max2;//final ans
	for (int i = 0; i < c; ++i)
		for (int j = 0; j < c; ++j)
			if (graph[i][j] != max2)//if we can reach from i to j (important)
				ans = max1(ans, graph[i][j]);//set ans to max2 of current ans and current distance

	cout << ans;
	return 0;
}
// time complexity --> O(c^3) --> feasible as c <= 230
#endif
