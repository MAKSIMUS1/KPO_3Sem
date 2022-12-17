#include <iostream>
#include "FST.h"
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	FST::FST fst1(			// недетермнированный конечный автомат (a+b)*aba
		(char*)"aabbabaaba",					// цепочка для распознования
		4,										// количество состяний
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),	// состояние 0 (начальное)
		FST::NODE(1, FST::RELATION('b', 2)),												// состояние 1
		FST::NODE(1, FST::RELATION('a', 3)),												// состояние 2
		FST::NODE()																			// состояние 3 (конечное)
	);
	if (FST::execute(fst1))
		cout << "Цепочка " << fst1.string << " распознана" << endl;
	else
		cout << "Цепочка " << fst1.string << " не распознана" << endl;

	FST::FST fst2(
		(char*)"aaabbbabba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if(FST::execute(fst2))
		cout << "Цепочка " << fst2.string << " распознана" << endl;
	else
		cout << "Цепочка " << fst2.string << " не распознана" << endl;
	
	// s+(d|p)+t

	FST::FST fst3(
		(char*)"sddpdppdt",
		4,
		FST::NODE(2, FST::RELATION('s', 0), FST::RELATION('s', 1)),
		FST::NODE(4, FST::RELATION('d', 1), FST::RELATION('d', 2), FST::RELATION('p', 1), FST::RELATION('p', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE()
	);
	if (FST::execute(fst3))
		cout << "Цепочка " << fst3.string << " распознана" << endl;
	else
		cout << "Цепочка " << fst3.string << " не распознана" << endl;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FST::FST Literal_str(
		(char*)"\'\'572\'0957\'",
		4,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(20,
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),
			FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),
			FST::RELATION('9', 1), FST::RELATION('0', 2), FST::RELATION('1', 2),
			FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),
			FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2),
			FST::RELATION('8', 2), FST::RELATION('9', 2)),
		FST::NODE(1, FST::RELATION('\'', 3)),
		FST::NODE()
	);
	if (FST::execute(Literal_str))
		cout << "Цепочка " << Literal_str.string << " распознана" << endl;
	else
		cout << "Цепочка " << Literal_str.string << " не распознана" << endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FST::FST Literal_str1(
		(char*)"\'5720957\'",
		4,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(20,
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),
			FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),
			FST::RELATION('9', 1), FST::RELATION('0', 2), FST::RELATION('1', 2),
			FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),
			FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2),
			FST::RELATION('8', 2), FST::RELATION('9', 2)),
		FST::NODE(1, FST::RELATION('\'', 3)),
		FST::NODE()
	);
	if (FST::execute(Literal_str1))
		cout << "Цепочка " << Literal_str1.string << " распознана" << endl;
	else
		cout << "Цепочка " << Literal_str1.string << " не распознана" << endl;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FST::FST Literal_str2(
		(char*)"\'\'",
		4,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(20,
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),
			FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),
			FST::RELATION('9', 1), FST::RELATION('0', 2), FST::RELATION('1', 2),
			FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),
			FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2),
			FST::RELATION('8', 2), FST::RELATION('9', 2)),
		FST::NODE(1, FST::RELATION('\'', 3)),
		FST::NODE()
	);
	if (FST::execute(Literal_str2))
		cout << "Цепочка " << Literal_str2.string << " распознана" << endl;
	else
		cout << "Цепочка " << Literal_str2.string << " не распознана" << endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	FST::FST Literal_str3(
		(char*)"\'57209df57\'",
		4,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(20,
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),
			FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),
			FST::RELATION('9', 1), FST::RELATION('0', 2), FST::RELATION('1', 2),
			FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),
			FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2),
			FST::RELATION('8', 2), FST::RELATION('9', 2)),
		FST::NODE(1, FST::RELATION('\'', 3)),
		FST::NODE()
	);
	if (FST::execute(Literal_str3))
		cout << "Цепочка " << Literal_str3.string << " распознана" << endl;
	else
		cout << "Цепочка " << Literal_str3.string << " не распознана" << endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	FST::FST Literal_str4(
		(char*)"\'5720957",
		4,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(20,
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1),
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),
			FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1),
			FST::RELATION('9', 1), FST::RELATION('0', 2), FST::RELATION('1', 2),
			FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),
			FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2),
			FST::RELATION('8', 2), FST::RELATION('9', 2)),
		FST::NODE(1, FST::RELATION('\'', 3)),
		FST::NODE()
	);
	if (FST::execute(Literal_str4))
		cout << "Цепочка " << Literal_str4.string << " распознана" << endl;
	else
		cout << "Цепочка " << Literal_str4.string << " не распознана" << endl;

	return 0;
};