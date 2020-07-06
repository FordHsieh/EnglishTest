/******************************************************************************/
/*    DPS header file -- EnglishTester.h                                      */
/*                                                                            */
/*    Description --                                                          */
/*        Read English Word and Make the test paper                           */
/*                                                                            */
/*    Remarks --                                                              */
/*                                                                            */
/*    Revise history --                                                       */
/*        Original development                by Y.C. at NSPO    july 07 2003 */
/*                                                                            */
/******************************************************************************/
#ifndef EnglishTester_H
#define EnglishTester_H

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FuncSUCCESS  true
#define FuncFAILURE false

// define struct text
typedef struct TEXT
{
	string EnglishWord;
	string ChineseWord;
} TeXT;

class EnglishTester
{
private:
	vector<TeXT>	WordVector;	// vector
	TeXT		test;
	fstream		file;		// file fstream
	string		filename;	// file name
	TeXT		questionWord[4];
	vector<TeXT>	FindSimWORD;

public:
	EnglishTester ();
	bool	set_fileName (const string &fileName);
	bool	open_file (void);
	bool	read_file (void);
	bool	writeFileE2C (void);
	bool	writeFileC2E (void);
	bool	writeFileE2C (const int &index);
	bool	writeFileC2E (const int &index);
	int	examinationE2C (void);
	int	examinationC2E (void);
	string	get_fileName (void);
};

#endif