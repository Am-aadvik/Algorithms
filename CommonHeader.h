
#define _CRT_SECURE_NO_DEPRECATE // suppress some compilation warning messages (for VC++ users)
#define _CRT_SECURE_NO_WARNINGS
#define  _SCL_SECURE_NO_WARNINGS

#include "ConsoleColor.h"

/**************************************ad-hoc Algorithm*************************************************/

//#define SPOJ_FISHMONGER
//#define CC_NTRIPLETS_01
//#define CC_ZCO22002_MESSAGES_01
//#define CC_ZCO14003_SMARTPHONE_01
#define CC_ZCO12001_MATCHBRACKETS_01
//#define CC_ZCO14001_VIDEOGAME_01

/*******************************************************************************************************/
#include <iostream>
#include <string>
#include <direct.h>
#include <conio.h>
#include <time.h>
#include <chrono>  

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
	freopen(output_file.c_str(), "w", stdout);							\
	return 0;															\
}																		\
	int nn = before_main1();											\
	MyProfiling mp;														\
	/*******************************************************************************************************/


