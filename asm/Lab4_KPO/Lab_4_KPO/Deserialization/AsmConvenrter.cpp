#include "stdafx.h"

using namespace std;

void AsmConvenrter::Invoke()
{
	file = ofstream("D:\\BSTU\\Kurs_2_1\\KPO\\asm\\Lab4_KPO\\Lab_4_KPO\\AssemblerCode\\assembler_code.asm");


	file.clear();

	file ASMHEADER;

	file << "FILESTR	 DB \"" << dataTypes.Char << "\", 0" << endl << endl;

	file << "FILEINT	 DD " << '0' + dataTypes.Int << endl << endl;
	file << "INTSTR		DB \"num: \", 0" << endl;

	file ASMFOOTER;

	file.close();
}
