
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
#define _CRT_SECURE_NO_WARNINGS
#define  _SCL_SECURE_NO_WARNINGS

#include "ConsoleColor.h"

/**************************************ad-hoc Algorithm*************************************************/

//#define SPOJ_FISHMONGER
//#define CC_NTRIPLETS_01
//#define CC_ZCO22002_MESSAGES_01
//#define CC_ZCO14003_SMARTPHONE_01
//#define CC_ZCO12001_MATCHBRACKETS_01
//#define CC_ZCO14002_SUPW_01
//#define CC_ZCO14001_VIDEOGAME_01
//#define CC_ZCO23001_PARCHMENT_01
//#define CC_FARFOR_FARFROMORIGIN_01
//#define CC_ARRHALVES_ARRAYHALVES_01
//#define CC_MINMAXARR_MINIMIZE_THE_MAXIMUM_01
//#define CC_ZCO23001_PARCHMENT_01
//#define CC_INOI2201_POSTING_01
//#define CC_INOI2203A_DIOCLETIAN_PART1
//#define CC_INOI2203B_DIOCLETIAN_PART2
//#define CC_SYMARRSWAP_SYMMETRIC_SWAPS_01
//#define CC_ZCO23002_WEIGHTAGE_01
//#define CC_INOI1601_WEALTH_DISPARITY_01
//#define CC_1202_TABLE_SUM_01
//#define CC_INOI1401_HIGHWAY_BYPASS_01
//#define USACO_JAN23_P1_LEADERS
//#define USACO_JAN23_P2_AIRCOWNDITIONING
//#define USACO_JAN23_P3_MOO_OPERATIONS
//#define USACO_JAN23_P2_FOLLOWDIR
//#define USACO_JAN23_P2_FOLLOWDIR_TC_GENERATOR
//#define CC_INOI2002_3XN_TILING
//#define CC_AMONGUS2_AMONG_US_01
//#define CC_INOI2202_CONQUEST_01
//#define CF_CONTEST1_PROBLEM_3
//#define CF_CONTEST1_PROBLEM_2
//#define CF_CONTEST1_PROBLEM_1
//#define USACO_FEB4_P1_FIND_AND_REPLACE
//#define UVA11367_FUEL_TANK
//#define UVA100_THE_3N_PROBLEM
//#define UVA11450_WEDDINGSHOPPING
//#define UVA10003_CUTTINGSTICKS
//#define UVA10684_JACKPOT
//#define UVA507_JILL_RIDES_AGAIN
//#define UVA10363_TIC_TAC_TOE
//#define UVA10653_BOMBS_NO_THEY_ARE_MINES
//#define CC_ZCO15002_VARIATION_01
//#define CC_ZCO13001_TOURNAMENT_01
//#define CC_ZCO14004_IPL
//#define CC_ZCO13003_CHEWING_01
//#define CC_ZCO12004_ROUND_TABLE_01
//#define CC_ZCO12002_WORMHOLES
//#define CC_ZCO15001_BREAK_UP
//#define CC_ZCO16001_BOOKSHELVES
//#define CC_ZCO15003_COVERING
//#define CC_ZCO16002_BAMBOO_ART_01
//#define CC_ZCO13002_LITTLE_RED_RINDING_HOOD
//#define CC_ZCO12003_MATCHED_BRACKETS2
//#define CC_ZCO15004_RACTANGLE
//#define CC_SINGTOUR_ZCO2019_SINGING_TOUR_01
//#define CC_ZCO17001_FOUR_SUM_01
//#define CC_ZCO13004_SAVE_SPACEMAN_SPIFF_01
//#define CC_ZCO22001_VACATION_01
//#define CC_MOVINTRL_MOVING_INTERVALS_01
//#define CC_ZCO20001_WEIRD_ORDERING_01
//#define CC_UPDOWNSEQ_ZCO2019_2_UPDOWN_SEQUENCES
//#define CC_STRIMPOR_SUBSTRING_IMPORTANCE_ZCO2018
//#define CC_ZCO20002_INTERLEAVINGS_ANS_BLOCKS_01
//#define CC_ZCO17002_RAYS_01
//#define USACO_FEB4_P1_FIND_AND_REPLACE
//#define CF_HOSSAM_AND_THE_COMBINATORICS_01
//#define CF_EXTREMELY_ROUND_01
//#define CF_ADD_A_AND_B_01


/*******************************************************************************************************/
#include <iostream>
#include <string>
#include <direct.h>
#include <conio.h>
#include <time.h>
#include <chrono>  
using namespace std;

#define CAT(A, B)   A##B
#define FILE_NAME1(A, B) CAT(A, B)
#define FILE_NAME(A, B) FILE_NAME1(A, B)


class MyProfiling
{
public:
	clock_t t;
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;

	MyProfiling() {
		t1 = std::chrono::high_resolution_clock::now();
		t = clock();
	}

	~MyProfiling() {
		t2 = std::chrono::high_resolution_clock::now();
		t = clock() - t;
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "All TCs took " << time_span.count() << " seconds\n";
		//printf ("All TCs took %.2f seconds\n", ((float)t)/CLOCKS_PER_SEC);
		_getch();
	}
};

#define READ_INPUT(A)													\
	int before_main1()													\
{																		\
	std::string path_dir = _getcwd(NULL, 0);							\
	std::string st = FILE_NAME1(#A, ".txt");							\
	std::string input_file = path_dir + "\\..\\input\\" + st;			\
	std::string output_file = path_dir + "\\..\\output\\" + st;			\
	freopen(input_file.c_str(), "r", stdin);							\
	return 0;															\
}																		\
	int nn = before_main1();											\
	MyProfiling mp;														\
	/*******************************************************************************************************/


