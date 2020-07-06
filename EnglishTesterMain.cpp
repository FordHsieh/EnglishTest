/******************************************************************************/
/*    DPS header file -- EnglishTesterMain.cpp                                */
/*                                                                            */
/*    Description --                                                          */
/*        Read English Word and Make the test paper Main Program              */
/*                                                                            */
/*    Remarks --                                                              */
/*                                                                            */
/*    Revise history --                                                       */
/*        Original development                by Y.C. at NSPO    july 07 2003 */
/*                                                                            */
/******************************************************************************/

// Standard C/C++ lib
#include <iostream>
#include <string>
#include <iomanip>

// define lib
#include "EnglishTester.h"

// namespace
using namespace std;


int main()
{
	EnglishTester englishTester;
	int select_value;
	int input_number;
	int i;
	string fileName;
	// show version
	cout << "/*******************************************/" <<endl;
	cout << "/*      EnglishTester v 1.0                */" <<endl;
	cout << "/*      program : �m�����_�������o         */" <<endl;
	cout << "/*      data    : 09/15 2003               */" <<endl;
	cout << "/*******************************************/" <<endl;
	cout << "�Ҩ�(1), �Ҩ�[�D���H��](2), �^½��(3), ��½�^(4), ���}(0) : ";
	cin  >> select_value;
	while ((select_value < 0) || (select_value > 6))
	{
		cout << "error number .. " << endl;
	}

	while (select_value != 0)
	{
		switch (select_value)
		{
		case 1:	// created english test file
			// write test file
			englishTester.writeFileE2C();
			englishTester.writeFileC2E();
			break;

		case 2:
			cout << "�n�ҴX�D : ";
			cin  >> input_number;
			englishTester.writeFileE2C(input_number);
			englishTester.writeFileC2E(input_number);
			break;

		case 3:
			getchar();
			do {
				input_number = englishTester.examinationE2C();
				getchar();
			} while ( input_number == 1);
			break;

		case 4:	
			getchar();
			do {
				input_number = englishTester.examinationC2E();
				getchar();
			} while ( input_number == 1);
			break;

		case 5: // administrator operation
			for (i = 1 ; i < 5002 ; i++)
			{
				cout << "�R�p....�ڪ��_�����o !!!  ";
				if (i % 3 == 0) cout << endl;
			}
			break;
		case 6:
			for ( i = 0 ; i < 5002 ; i++)
			{
				cout << "�_��~~~�گu���n�R�p��!!!";
				if (i % 3 == 0) cout << endl;
			}
			break;
		}

		cout << "�Ҩ�(1), �Ҩ�[�D���H��](2), �^½��(3), ��½�^(4), ���}(0) : ";
		cin  >> select_value;
		while ((select_value < 0) || (select_value > 6))
		{
			cout << "error number .. " << endl;
		}	
	}

	return 0;
}