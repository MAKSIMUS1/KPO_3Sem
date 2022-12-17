#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>

#include "Error.h"	//обработка ошибок
#include "Parm.h"	//обработка параметров
#include "Log.h"	//работа с протоколом
#include "In.h"		//ввод исходного файла

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	std::cout << " --- ТЕСТ IN::getin --- " << std::endl << std::endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines << std::endl;
		std::cout << "Пропущенно: " << in.ignor << std::endl;
		//std::ofstream Out(parm.out);
		//Out << in.text;
		//Out.close();
		Lex_analysis::Lexical_analysis(parm, in);
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	};

	Log::LOG log;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
		Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};

	system("pause");
	return 0;
}

