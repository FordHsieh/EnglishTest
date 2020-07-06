/******************************************************************************/
/*    DPS header file -- EnglishTester.cpp                                    */
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
#include "EnglishTester.h"

/* EnglishTester member function -- constructor */
EnglishTester::EnglishTester ()
{
	// set and open default value
	filename = "minna.txt";
	set_fileName(filename);
	open_file ();
	read_file ();

	return;
}


/* EnglishTester member function -- set_fileName */
bool	EnglishTester::set_fileName (const string &fileName)
{
	// set file name
	filename = fileName;

	return FuncSUCCESS;
}

/* EnglishTester menber function -- open_file */
bool	EnglishTester::open_file (void)
{
	file.open(filename.c_str(), ios::in);
	// check the file open success
	if (!file)
	{
		cout << filename << " open failure ..." << endl;
		return FuncFAILURE;
	}

	return FuncSUCCESS;
}

/* EnglishTester member function -- read_file() */
bool	EnglishTester::read_file (void)
{
	string strEword;
	string strCword;
	while(file >> strEword >> strCword)
	{
		// clean test object
		test.EnglishWord.erase(0,test.EnglishWord.max_size());
		test.ChineseWord.erase(0,test.ChineseWord.max_size());

		// set English and Chinese word
		test.EnglishWord = strEword;
		test.ChineseWord = strCword;

		// cout << "English Word = " 
		//      << test.EnglishWord << endl;
		// cout << "Chinese Word = " 
		//      << test.ChineseWord <<endl;

		// push TeXT struct value in WordVector
		
		WordVector.push_back (test);
	}

	return FuncSUCCESS;
}

/* EnglishTester member function -- writeFileE2C */
bool	EnglishTester::writeFileE2C (void)
{
	cout << "processing English To Chinese paper..... " << endl;

	fstream writefile;
	writefile.open("TextPaper_EnglishToChinese.txt", ios::out);
	for (int count = 0, i = 0 ; count < 80 ; count ++)
	{
	writefile << setiosflags(ios::left) << setw(12);
	writefile << WordVector[i++].EnglishWord << " = _____________ ";
	writefile << setiosflags(ios::left) << setw(12); 
	writefile << WordVector[i++].EnglishWord << " = _____________ ";
	writefile << endl;
	}

	writefile.close ();
	cout << "processing finish ..." << endl;
	
	return FuncSUCCESS;
}

/* EnglishTester member function -- writeFileE2C */
bool	EnglishTester::writeFileE2C (const int &index)
{
	cout << "processing English To Chinese paper (rand)..... " << endl;

	srand( (unsigned)time( NULL ) );
	int		number;
	int		count = 1;
	int		vector_size = WordVector.size();
	fstream writefile;
	writefile.open("TextPaper_EnglishToChinese(rand).txt", ios::out);
	do {
		number = rand ();
		if (number <= vector_size)
		{
			writefile << setiosflags(ios::left) << setw(12);
			writefile << WordVector[number].EnglishWord << " = _____________ ";
			if (count % 2 == 0)	writefile << endl;
			count ++;
		}		
	} while (count != index);

	writefile.close ();
	cout << "processing finish ..." << endl;	
	return FuncSUCCESS;
}

/* EnglishTester member function -- writeFileC2E */
bool	EnglishTester::writeFileC2E (void)
{
	cout << "processing Chinese To English paper..... " << endl;

	fstream writefile;
	int WordSize;
	writefile.open("TestPaper_ChineseToEnglish.txt", ios::out);
	for (int count = 0 , i = 0 ; count < 20 ; count++)
	{
	writefile << setiosflags(ios::left) << setw(20);
	
	i++;
	WordSize = WordVector[i].EnglishWord.size() - 1;
	writefile << WordVector[i].ChineseWord << " = "
		  << WordVector[i].EnglishWord[0] << "__________"
		  << WordVector[i].EnglishWord[WordSize];
	writefile << setiosflags(ios::left) << setw(20);
	
	i++;
	WordSize = WordVector[i].EnglishWord.size() - 1;
	writefile << WordVector[i].ChineseWord << " = "
		  << WordVector[i].EnglishWord[0] << "__________"
		  << WordVector[i].EnglishWord[WordSize];
	writefile << endl;
	}

	writefile.close ();
	cout << "processing finish ..." << endl;
	return FuncSUCCESS;
}

/* EnglishTester member function -- writeFileC2E */
bool	EnglishTester::writeFileC2E (const int &index)
{
	cout << "processing Chinese To English paper(rand)..... " << endl;

	srand( (unsigned)time( NULL ) );
	int		number;
	int		count = 1;
	int		vector_size = WordVector.size();
	int		WordSize;
	fstream writefile;
	writefile.open("TestPaper_ChineseToEnglish(rand).txt", ios::out);
	do {
		number = rand ();
		if (number <= vector_size)
		{
			WordSize = WordVector[number].EnglishWord.size() - 1;
			writefile << setiosflags(ios::left) << setw(20);
			writefile << WordVector[number].ChineseWord << " = "
					  << WordVector[number].EnglishWord[0] << "__________"
					  << WordVector[number].EnglishWord[WordSize];
			if (count % 2 == 0)	writefile << endl;
			count ++;
		}
	} while (count != index);

	writefile.close();
	cout << "processing finish ..." << endl;
	return FuncSUCCESS;
}

int		EnglishTester::examinationE2C (void)
{
	// clean all the FindSimWORD vector data
	FindSimWORD.clear();
	system ("cls");
	srand( (unsigned)time( NULL ) );
	char	str[81];
	int		number;
	int		AnswerNum;
	int		vector_size = WordVector.size();
	vector<int> rec;

START:

	// set question word empty
	questionWord[0].EnglishWord = "";
	questionWord[0].ChineseWord = "";
	questionWord[1].EnglishWord = "";
	questionWord[1].ChineseWord = "";
	questionWord[2].EnglishWord = "";
	questionWord[2].ChineseWord = "";
	questionWord[3].EnglishWord = "";
	questionWord[3].ChineseWord = "";

	// pick the rand number
	do {
		number = rand ();
	} while (number >= vector_size);

	int	breakcount = 1;		// for check break
	string	FindWord;		// for find word
	// front
	questionWord[0] = WordVector[number];

	// set finding word
	FindWord = questionWord[0].EnglishWord;

	// cout << "FindWord = " << FindWord << endl;
	for (int k = 0 ; k < questionWord[0].EnglishWord.size() ; k++)
	{
		if ((FindWord.size() == 1) || (FindWord == "")) {}
		else
		{
			for (int WordCount = 0 ; WordCount < vector_size ; WordCount++)
			{
				// cout << "loop4" << endl;
				int index = WordVector[WordCount].EnglishWord.find(FindWord);
				if ((index != string::npos) && (index == 0))	// check the finding word
				{
					if (questionWord[0].EnglishWord 
						!= WordVector[WordCount].EnglishWord)
					{
						if (FindSimWORD.size() == 0)
						{
							FindSimWORD.push_back(WordVector[WordCount]);
							// cout << "findsimword == 0" << endl;
						}
						else
						{
							int count = 0;
							do {
								if (FindSimWORD[count].EnglishWord
									== WordVector[WordCount].EnglishWord)
								{
									// cout
									// << "erase value : " 
									// << FindSimWORD[count].EnglishWord << endl;
									FindSimWORD.erase(FindSimWORD.begin() + 
																	count);
								}
								count ++;
								// cout << "cout = " << count << endl;
							} while (count < FindSimWORD.size());
							// cout << "push back" << endl;
							FindSimWORD.push_back(WordVector[WordCount]);
						}
					}
				}
			}
		}

		FindWord = FindWord.erase (FindWord.size() - 1, 1);
		// cout << "FindWord = " << FindWord <<endl;
	}
	
	// check word count then 4
	if (FindSimWORD.size() < 4) goto START;
	// cout << "FindSimWORD = " << FindSimWORD.size() << endl;	
	vector_size = FindSimWORD.size();
	// set vector rec
	for (int ii = 0 ; ii < vector_size ; ii++)	rec.push_back (ii);
	random_shuffle (rec.begin(), rec.end());

	questionWord[0] = FindSimWORD[rec[0]];
	questionWord[1] = FindSimWORD[rec[1]];
	questionWord[2] = FindSimWORD[rec[2]];
	questionWord[3] = FindSimWORD[rec[3]];

	// set the AnswerNum
	do {
		AnswerNum = rand();
		AnswerNum = (AnswerNum % 4) + 1;
	} while (AnswerNum > 4);

	cout << " " << questionWord[AnswerNum - 1].EnglishWord << " : " << endl;
	cout << " 1) " << questionWord[0].ChineseWord << endl;
	cout << " 2) " << questionWord[1].ChineseWord << endl;
	cout << " 3) " << questionWord[2].ChineseWord << endl;
	cout << " 4) " << questionWord[3].ChineseWord << endl;
	cout << "number : ";
	cin.getline (str, 80);	str[1] = '\0';
	if (!strcmp (str, ""))
	{
		cout << "答錯了，正確答案是 : "
			 << questionWord[AnswerNum - 1].ChineseWord << endl;
		return 1;
	}
	
	if (atoi (str) == 0)
	{
		cout << "不玩嚕~~!!!! 但是還是要親親，啵~~!!!";
		return 0;
	}

	if (AnswerNum == atoi (str))
	{
		cout << "答對了 ~~~~ 親一個，啵!!!" << endl;
	}
	else if (AnswerNum != atoi (str))
	{
		cout << "答錯了，正確答案是 : "
			 << questionWord[AnswerNum - 1].ChineseWord << endl;
	}

	
	return 1;
}

int		EnglishTester::examinationC2E (void)
{
	// clean all the FindSimWORD vector data
	FindSimWORD.clear();
	system ("cls");
	srand( (unsigned)time( NULL ) );
	char	str[81];
	int		number;
	int		AnswerNum;
	int		vector_size = WordVector.size();
	vector<int> rec;

START:
	// pick the rand number
	do {
		number = rand ();
	} while (number >= vector_size);

	int	breakcount = 1;		// for check break
	string	FindWord;		// for find word
	// front
	questionWord[0].ChineseWord = WordVector[number].ChineseWord;
	questionWord[0].EnglishWord = WordVector[number].EnglishWord;
	
	// set finding word
	FindWord = questionWord[0].EnglishWord;

	// cout << "FindWord = " << FindWord << endl;
	for (int k = 0 ; k < questionWord[0].EnglishWord.size() ; k++)
	{
		if ((FindWord.size() == 1) || (FindWord == "")) {}
		else
		{
			for (int WordCount = 0 ; WordCount < vector_size ; WordCount++)
			{
				int index = WordVector[WordCount].EnglishWord.find(FindWord);
				if ((index != string::npos) && (index == 0))	// check the finding word
				{
					if (questionWord[0].EnglishWord 
						!= WordVector[WordCount].EnglishWord)
					{
						if (FindSimWORD.size() == 0)
						{
							FindSimWORD.push_back(WordVector[WordCount]);
							// cout << "findsimword == 0" << endl;
						}
						else
						{
							int count = 0;
							do {
								if (FindSimWORD[count].EnglishWord 
									== WordVector[WordCount].EnglishWord)
								{
									// cout 
									// << "erase value : " 
									// << FindSimWORD[count].EnglishWord << endl;
									FindSimWORD.erase(FindSimWORD.begin() + 
																	count);
								}
								count ++;
								// cout << "cout = " << count << endl;
							} while (count < FindSimWORD.size());
							// cout << "push back" << endl;
							FindSimWORD.push_back(WordVector[WordCount]);
						}
					}
				}
			}
		}
						
		FindWord = FindWord.erase (FindWord.size() - 1, 1);
		// cout << "FindWord = " << FindWord <<endl;
	}
	
	// check word count then 4
	if (FindSimWORD.size() < 4) goto START;
	// cout << "FindSimWORD = " << FindSimWORD.size() << endl;	
	vector_size = FindSimWORD.size();
	// set vector rec
	for (int ii = 0 ; ii < vector_size ; ii++)	rec.push_back (ii);
	random_shuffle (rec.begin(), rec.end());

	questionWord[0] = FindSimWORD[rec[0]];
	questionWord[1] = FindSimWORD[rec[1]];
	questionWord[2] = FindSimWORD[rec[2]];
	questionWord[3] = FindSimWORD[rec[3]];

	// set the AnswerNum
	do {
		AnswerNum = rand();
		AnswerNum = (AnswerNum % 4) + 1;
	} while (AnswerNum > 4);

	cout << " " << questionWord[AnswerNum - 1].ChineseWord << " : " << endl;
	cout << " 1) " << questionWord[0].EnglishWord << endl;
	cout << " 2) " << questionWord[1].EnglishWord << endl;
	cout << " 3) " << questionWord[2].EnglishWord << endl;
	cout << " 4) " << questionWord[3].EnglishWord << endl;
	cout << "number : ";
	cin.getline (str, 80);	str[1] = '\0';
	if (!strcmp (str, ""))
	{
		cout << "答錯了，正確答案是 : "
			 << questionWord[AnswerNum - 1].EnglishWord << endl;
		return 1;
	}
	
	if (atoi (str) == 0)
	{
		cout << "不玩嚕~~!!!! 但是還是要親親，啵~~!!!";
		return 0;
	}

	if (AnswerNum == atoi (str))
	{
		cout << "答對了 ~~~~ 親一個，啵!!!" << endl;
	}
	else if (AnswerNum != atoi (str))
	{
		cout << "答錯了，正確答案是 : "
			 << questionWord[AnswerNum - 1].EnglishWord << endl;
	}

	return 1;
}

/* EnglishTester member function -- get_fileName */
string	EnglishTester::get_fileName (void)
{
	return filename;
}
